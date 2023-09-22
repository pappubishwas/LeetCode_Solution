#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution;

    int m, n;
    std::cout << "Enter the number of rows: ";
    std::cin >> m;
    std::cout << "Enter the number of columns: ";
    std::cin >> n;

    int result = solution.uniquePaths(m, n);
    std::cout << "The number of unique paths in the grid is: " << result << std::endl;

    return 0;
}
