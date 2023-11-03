#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        int p = target.size(), j = 0;
        std::vector<std::string> ans;
        for (int i = 1; i <= n && j < p; i++) {
            if (target[j] == i) {
                ans.push_back("Push");
                j++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> target = {1, 3};
    int n = 3;
    std::vector<std::string> result = solution.buildArray(target, n);
    std::cout << "Result: ";
    for (const auto& str : result) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
