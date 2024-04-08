#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void long_operation() {
    using namespace chrono_literals;
    this_thread::sleep_for(150ms);
}

int main() {
    chrono::time_point t1 = chrono::high_resolution_clock::now();
    long_operation();
    chrono::time_point t2 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> time_taken = t2 - t1;

    cout << "Time taken: " << time_taken.count() << "ms" << endl;

    return 0;
}
