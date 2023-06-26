#include <iostream>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
std::string result;
bool isReady = false;

// A function that performs some I/O operation asynchronously
void performAsyncIO()
{
    // Simulating an I/O operation that takes some time
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Update the result
    std::lock_guard<std::mutex> lock(mtx);
    result = "Async I/O operation completed.";
    isReady = true;

    // Notify the waiting thread
    cv.notify_one();
}

int main()
{
    // Start the async I/O operation in a separate thread
    std::thread ioThread(performAsyncIO);

    // Do some other work while the I/O operation is in progress
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Performing other tasks " << i + 1 << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Wait for the I/O operation to complete
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return isReady; });
    }

    // Print the result
    std::cout << "Result: " << result << std::endl;

    // Join the IO thread
    ioThread.join();

    return 0;
}
