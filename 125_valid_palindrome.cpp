#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string st = "";
        int n = s.size(), l = 0;
        for (int i = 0; i < n; i++)
        {
            if ((s[i] >= 'a' and s[i] <= 'z') || (s[i] >= 'A' and s[i] <= 'Z'))
                st += tolower(s[i]);
            else if ((s[i] >= '0' and s[i] <= '9'))
                st += s[i];
        }
        n = st.size() - 1;
        while (l < n)
        {
            if (st[l] != st[n])
                return false;
            l++;
            n--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    bool is_palindrome = s.isPalindrome(str);
    if (is_palindrome)
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;
    return 0;
}