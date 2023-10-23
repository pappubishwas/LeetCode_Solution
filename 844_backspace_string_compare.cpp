#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int k = processString(s);
        int p = processString(t);

        if (k != p)
            return false;

        for (int i = 0; i < k; i++)
        {
            if (s[i] != t[i])
                return false;
        }

        return true;
    }

private:
    int processString(string &str)
    {
        int k = 0;
        for (char c : str)
        {
            if (c != '#')
            {
                str[k++] = c;
            }
            else if (k > 0)
            {
                k--;
            }
        }
        return k;
    }
};

// Sample main function
int main()
{
    Solution sol;
    string s1 = "ab#c";
    string t1 = "ad#c";
    string s2 = "ab##";
    string t2 = "c#d#";

    cout << "Are the strings equal after backspace processing? " << sol.backspaceCompare(s1, t1) << endl;
    cout << "Are the strings equal after backspace processing? " << sol.backspaceCompare(s2, t2) << endl;

    return 0;
}
