#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class SeatManager {
private:
    int last;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

public:
    SeatManager(int n) : last(0) {}

    int reserve() {
        if (pq.empty()) {
            return ++last;
        } else {
            int seat = pq.top();
            pq.pop();
            return seat;
        }
    }

    void unreserve(int seatNumber) {
        if (seatNumber == last) {
            --last;
        } else {
            pq.push(seatNumber);
        }
    }
};
int main() {
    // Create an instance of SeatManager
    SeatManager seatManager(5);

    // Reserve some seats
    std::cout << seatManager.reserve() << std::endl; // Output: 1
    std::cout << seatManager.reserve() << std::endl; // Output: 2

    // Unreserve a seat
    seatManager.unreserve(1);

    // Reserve another seat
    std::cout << seatManager.reserve() << std::endl; // Output: 1 (The unreserved seat is reused)

    // Reserve more seats
    std::cout << seatManager.reserve() << std::endl; // Output: 3
    std::cout << seatManager.reserve() << std::endl; // Output: 4
    std::cout << seatManager.reserve() << std::endl; // Output: 5

    // Unreserve a seat
    seatManager.unreserve(4);

    // Reserve another seat
    std::cout << seatManager.reserve() << std::endl; // Output: 4 (The unreserved seat is reused)

    return 0;
}
