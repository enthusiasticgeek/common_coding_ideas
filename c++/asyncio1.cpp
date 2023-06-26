#include <iostream>
#include <future>

// A function that performs some I/O operation asynchronously
std::string performAsyncIO()
{
    // Simulating an I/O operation that takes some time
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return "Async I/O operation completed.";
}

int main()
{
    // Start the async I/O operation
    std::future<std::string> resultFuture = std::async(std::launch::async, performAsyncIO);

    // Do some other work while the I/O operation is in progress
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Performing other tasks " << i + 1 << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Check if the I/O operation has completed
    if (resultFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        // I/O operation is complete, get the result
        std::string result = resultFuture.get();
        std::cout << "Result: " << result << std::endl;
    }
    else
    {
        // I/O operation is still in progress
        std::cout << "I/O operation still in progress." << std::endl;
    }

    return 0;
}
