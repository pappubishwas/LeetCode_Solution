#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Calculate n choose r (nCr) using a loop
    int calculateCombination(int n, int r)
    {
        long long result = 1;
        for (int i = 0; i < r; i++)
        {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }

    vector<int> getRow(int rowIndex)
    {
        // Initialize a vector to represent The last Row
        vector<int> lastRow;

        for (int j = 0; j <= rowIndex; j++)
        {
            // Calculate and insert the binomial coefficient (nCr) into the row
            lastRow.push_back(calculateCombination(rowIndex, j));
        }

        return lastRow;
    }
};

int main()
{
    Solution solution;
    int rowIndex = 3; // Change the value of rowIndex as needed

    vector<int> result = solution.getRow(rowIndex);

    // Output the resulting vector
    cout << "Row: ";
    for (auto val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
