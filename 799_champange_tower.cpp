#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        if (poured == 0)
            return 0;
        vector<double> ans;
        ans.push_back(poured);
        while (query_row-- > 0)
        {
            vector<double> temp;
            temp.push_back(max((ans[0] - 1) / 2, 0.00000));
            for (int i = 1; i < ans.size(); i++)
            {
                temp.push_back(max((ans[i - 1] - 1) / 2, 0.00000) + max((ans[i] - 1) / 2, 0.00000));
            }
            temp.push_back(max((ans[0] - 1) / 2, 0.00000));
            ans = temp;
        }
        return min(1.0, ans[query_glass]);
    }
};

int main()
{
    Solution solution;
    int poured = 25;
    int query_row = 6;
    int query_glass = 1;
    double result = solution.champagneTower(poured, query_row, query_glass);
    cout << "The amount of champagne in the glass (" << query_row << ", " << query_glass << ") is: " << result << endl;
    return 0;
}
