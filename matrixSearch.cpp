#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m, n, i, j;
        m = matrix.size();
        n = matrix[0].size();
        for (i = 0; i < m; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
                int s, e;
                s = 0;
                e = n - 1;
                while (s <= e) {
                    int med = (s + e) / 2;
                    if (target == matrix[i][med])
                        return true;
                    else if (target > matrix[i][med])
                        s = med + 1;
                    else
                        e = med - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    bool result = solution.searchMatrix(matrix, target);

    if (result) {
        std::cout << "Target " << target << " found in the matrix." << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the matrix." << std::endl;
    }

    return 0;
}
