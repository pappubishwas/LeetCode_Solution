#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> s1;
        unordered_map<char, int> t1;
        for (int i = 0; i < s.size(); i++)
        {
            s1[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            t1[t[i]]++;
        }
        for (auto mp : t1)
        {
            if (s1[mp.first] != mp.second)
            {
                return mp.first;
            }
        }
        return s[0];
    }
};

int main()
{
    Solution solution;
    string s = "abcd";
    string t = "abcde";
    char result = solution.findTheDifference(s, t);
    cout << "The extra character in string t is: " << result << endl;
    return 0;
}
