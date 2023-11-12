#include <iostream>
#include <vector>

class Solution {
public:
    long long maxSpending(std::vector<std::vector<int>>& values) {
        std::vector<int> ans;
        for (int i = 0; i < values.size(); i++) {
            for (int j = 0; j < values[0].size(); j++)
                ans.push_back(values[i][j]);
        }
        sort(ans.begin(), ans.end());
        long long res = 0;
        for (int i = 0; i < ans.size(); i++)
            res += static_cast<long long>(i + 1) * ans[i];

        return res;
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::vector<std::vector<int>> values = {
        {3, 5, 1},
        {2, 8, 7},
        {1, 6, 4}
    };

    long long result = solution.maxSpending(values);

    std::cout << "Maximum Spending: " << result << std::endl;

    return 0;
}
