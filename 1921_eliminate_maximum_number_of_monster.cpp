#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) {
        int n = dist.size();
        std::vector<double> timeCity(n);
        
        for (int i = 0; i < n; ++i) {
            timeCity[i] = static_cast<double>(dist[i]) / speed[i];
        }
        
        std::sort(timeCity.begin(), timeCity.end());
        
        for (int i = 0; i < n; ++i) {
            if (timeCity[i] <= i) {
                return i;
            }
        }
        
        return n;
    }
};

int main() {
    Solution solution;
    std::vector<int> dist = {1, 3, 4};
    std::vector<int> speed = {1, 1, 1};

    int result = solution.eliminateMaximum(dist, speed);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
