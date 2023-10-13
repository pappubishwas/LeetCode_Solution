#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void makeparan(vector<string> &ans, int l, int r, int lu, string s)
    {
        if (l == 0 && r == 0)
        {
            ans.push_back(s);
            return;
        }
        if (l > 0)
        {
            makeparan(ans, l - 1, r, lu + 1, s + '(');
        }
        if (lu > 0 && r > 0)
        {
            makeparan(ans, l, r - 1, lu - 1, s + ')');
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        makeparan(ans, n, n, 0, "");
        return ans;
    }
};

int main()
{
    Solution solution;
    int n = 3; // Replace with your desired value of n.
    vector<string> result = solution.generateParenthesis(n);
    cout << "Generated Parentheses: " << endl;
    for (const auto &s : result)
    {
        cout << s << endl;
    }
    return 0;
}
