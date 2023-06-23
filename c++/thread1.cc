#include <iostream>
#include <thread>
#include <memory>
#include <mutex>

std::mutex mutex;  // Mutex for synchronizing access to shared data

void printMessage(const std::shared_ptr<std::string>& message) {
    std::lock_guard<std::mutex> lock(mutex);  // Lock the mutex

    std::cout << "Message: " << *message << std::endl;

    // Unlock the mutex automatically when lock_guard goes out of scope
}

int main() {
    std::shared_ptr<std::string> message = std::make_shared<std::string>("Hello, C++ Threads!");

    std::thread t1(printMessage, message);
    std::thread t2(printMessage, message);

    t1.join();
    t2.join();

    return 0;
}
