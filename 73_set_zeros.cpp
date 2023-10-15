#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), i = 0, j = 0, d = 2147483650;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                    mat[i][j] = d;
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (mat[i][j] == d)
                {
                    for (int k = 0; k < n; k++)
                        if (mat[k][j] != d)
                            mat[k][j] = 0;
                    for (int k = 0; k < m; k++)
                        if (mat[i][k] != d)
                            mat[i][k] = 0;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (mat[i][j] == d)
                    mat[i][j] = 0;
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << "Original Matrix:" << endl;
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    solution.setZeroes(matrix);
    cout << "Matrix after setting zeroes:" << endl;
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
