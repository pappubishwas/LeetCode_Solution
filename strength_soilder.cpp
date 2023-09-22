#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rowStrengths;
        for (int i = 0; i < mat.size(); ++i) {
            int strength = accumulate(mat[i].begin(), mat[i].end(), 0);
            rowStrengths.push_back({strength, i});
        }

        sort(rowStrengths.begin(), rowStrengths.end());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(rowStrengths[i].second);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example input: a matrix of soldiers' strengths
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    int k = 3; // Number of weakest rows to find

    vector<int> weakestRows = solution.kWeakestRows(mat, k);

    // Print the indices of the k weakest rows
    cout << "Indices of the " << k << " weakest rows: ";
    for (int i : weakestRows) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
