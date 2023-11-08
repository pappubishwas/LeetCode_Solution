#include <iostream>
#include <cmath>

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy) return t != 1;
        return (std::max(std::abs(sx - fx), std::abs(sy - fy)) <= t);
    }
};

int main() {
    Solution solution;
    int sx, sy, fx, fy, t;
    std::cout << "Enter starting x-coordinate: ";
    std::cin >> sx;
    std::cout << "Enter starting y-coordinate: ";
    std::cin >> sy;
    std::cout << "Enter final x-coordinate: ";
    std::cin >> fx;
    std::cout << "Enter final y-coordinate: ";
    std::cin >> fy;
    std::cout << "Enter time: ";
    std::cin >> t;
    std::cout << std::boolalpha << solution.isReachableAtTime(sx, sy, fx, fy, t) << std::endl;
    return 0;
}
