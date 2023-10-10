#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int t = 0, l = 0, b = matrix.size() - 1, r = matrix[0].size() - 1;
        while (l <= r && t <= b)
        {
            for (int i = l; i <= r; i++)
                ans.push_back(matrix[t][i]);
            t++;
            for (int i = t; i <= b; i++)
                ans.push_back(matrix[i][r]);
            r--;
            if (l > r || t > b)
                break;
            for (int i = r; i >= l; i--)
                ans.push_back(matrix[b][i]);
            b--;
            for (int i = b; i >= t; i--)
                ans.push_back(matrix[i][l]);
            l++;
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Create a sample 2D matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<int> result = solution.spiralOrder(matrix);

    // Print the elements in spiral order
    std::cout << "Spiral Order: ";
    for (int num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
