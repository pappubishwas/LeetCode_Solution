#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        vector<string> ans(n + 1, "");
        ans[1] = "1";
        int i = 2;
        while (i <= n)
        {
            string s = "", t;
            t = ans[i - 1];
            int count = 1;
            char ch = t[0];
            for (int j = 1; j < t.size(); j++)
            {
                if (ch != t[j])
                {
                    s += to_string(count);
                    s += ch;
                    ch = t[j];
                    count = 1;
                }
                else
                    count++;
            }
            s += to_string(count);
            s += ch;
            ans[i] = s;
            i++;
        }
        return ans[n];
    }
};

int main()
{
    Solution solution;
    int n = 5; // Replace with your desired value of n.
    string result = solution.countAndSay(n);
    cout << "Result: " << result << endl;
    return 0;
}
