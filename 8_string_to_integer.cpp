#include <cmath>
#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        long long int n = s.size(), flag = 0;
        queue<int> q;
        char ch;
        for (int i = 0; i < n; i++)
        {
            if (s[i] <= '9' && s[i] >= '0')
            {
                q.push(s[i] - '0');
                flag = 1;
            }
            else if (flag == 0 && (s[i] == '-' || s[i] == '+'))
            {
                ch = s[i];
                flag = 1;
            }
            else if (flag == 1 || s[i] != ' ')
            {
                break;
            }
        }
        while (q.front() == 0)
            q.pop();
        int i = q.size() - 1;
        n = 0;
        if (i > 10)
        {
            if (ch == '-')
                return -pow(2, 31);
            else
                return pow(2, 31) - 1;
        }
        while (!q.empty())
        {
            int p = q.front();
            n += p * pow(10, i);
            i--;
            q.pop();
        }
        if (ch == '-')
            n = -n;
        if (n > (pow(2, 31) - 1))
            n = pow(2, 31) - 1;
        else if (n < (-pow(2, 31)))
            n = -pow(2, 31);
        return n;
    }
};

int main()
{
    Solution solution;

    string str = "42"; // Example string to convert

    int result = solution.myAtoi(str);

    cout << "Converted Integer: " << result << endl;

    return 0;
}
