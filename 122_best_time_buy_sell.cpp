#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        if (p.size() <= 1)
            return 0;
        int totalpro = 0;
        for (int i = 1; i < p.size(); i++)
        {
            if (p[i - 1] < p[i])
                totalpro += p[i] - p[i - 1];
        }
        return totalpro;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int maxProfit = sol.maxProfit(prices);
    cout << "Maximum Profit: " << maxProfit << endl;
    return 0;
}
