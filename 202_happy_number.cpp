#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_map<int, int> mp;
        mp[n] = 1;
        while (n != 1)
        {
            int sum = 0;
            while (n > 0)
            {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            if (mp[sum] == 1)
                return false;
            mp[sum] = 1;
            n = sum;
        }
        return true;
    }
};

int main()
{
    Solution s;
    int num = 19;
    bool is_happy = s.isHappy(num);
    if (is_happy)
        cout << num << " is a happy number." << endl;
    else
        cout << num << " is not a happy number." << endl;
    return 0;
}