#include <cmath>
#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long long int flag = 0, n = 0;
        if (x < 0)
            flag = 1;
        x = abs(x);
        queue<int> q;
        while (x > 0)
        {
            q.push(x % 10);
            x /= 10;
        }
        int i = q.size() - 1;
        while (!q.empty())
        {
            int p = q.front();
            n += p * pow(10, i);
            i--;
            q.pop();
        }
        if (flag == 1)
            n = -n;
        if (n > (pow(2, 31) - 1) || n < (-pow(2, 31)))
            return 0;
        return n;
    }
};

int main()
{
    Solution solution;

    int x = 123; // Example integer to reverse

    int reversed = solution.reverse(x);

    cout << "Reversed Integer: " << reversed << endl;

    return 0;
}
