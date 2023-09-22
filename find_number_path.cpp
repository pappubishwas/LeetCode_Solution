
#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        // Implementation of uniquePathsWithObstacles function goes here
        // You can use obstacleGrid[i][j] to access elements of the grid
        int m,n;
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();

       std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
       if(obstacleGrid[m-1][n-1]==1)
       return 0;
       dp[0][0]=1;
       for(int i=0;i<m;i++){
        for (int j = 0; j < n; j++)
        {
            if(obstacleGrid[i][j]==0){
                if(j!=n-1)
                dp[i][j+1]+=dp[i][j];
                if(i!=m-1)
                dp[i+1][j]+=dp[i][j];
            }
        }
        
       }
       return dp[m-1][n-1];
    }
};


int main() {
    Solution solution;
    
    // Example obstacle grid
    std::vector<std::vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    
    int result = solution.uniquePathsWithObstacles(obstacleGrid);
    
    std::cout << "Number of unique paths: " << result << std::endl;
    
    return 0;
}
