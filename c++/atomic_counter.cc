#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);  // Atomic counter

/*
Inside the incrementCounter function, each thread performs a loop where it increments the counter by 1 
using fetch_add atomic operation with the relaxed memory ordering. 
This operation atomically adds 1 to the counter without any synchronization overhead.
*/

void incrementCounter() {
    for (int i = 0; i < 1000000; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    t1.join();
    t2.join();

    std::cout << "Counter value: " << counter << std::endl;

    return 0;
}
