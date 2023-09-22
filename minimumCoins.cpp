#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int a = 1; a <= amount; ++a) {
            for (int c : coins) {
                if (a - c >= 0) {
                    dp[a] = std::min(dp[a], 1 + dp[a - c]);
                }
            }
        }

        return dp[amount] != amount + 1 ? dp[amount] : -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = solution.coinChange(coins, amount);
    std::cout << "Minimum number of coins needed to make " << amount << " cents: " << result << std::endl;

    return 0;
}
