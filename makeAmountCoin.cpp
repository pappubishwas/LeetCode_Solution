#include <iostream>
#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        std::vector<std::vector<int>> dp(amount + 1, std::vector<int>(coins.size() + 1, 0));
        for (int i = 0; i <= coins.size(); ++i) {
            dp[0][i] = 1;
        }

        for (int a = 1; a <= amount; ++a) {
            for (int i = coins.size() - 1; i >= 0; --i) {
                dp[a][i] = dp[a][i + 1];
                if (a - coins[i] >= 0) {
                    dp[a][i] += dp[a - coins[i]][i];
                }
            }
        }
        return dp[amount][0];
    }
};

int main() {
    Solution solution;
    int amount = 5;
    std::vector<int> coins = {1, 2, 5};
    int result = solution.change(amount, coins);
    std::cout << "Number of combinations to make " << amount << " cents: " << result << std::endl;
    return 0;
}
