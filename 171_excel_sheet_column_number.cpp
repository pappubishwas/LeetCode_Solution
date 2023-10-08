#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int l = columnTitle.size(), i = 1, sum = 0;
        for (i = 1; i <= l; i++)
        {
            int t = columnTitle[i - 1] - 'A' + 1;
            sum += (t * pow(26, l - i));
        }
        return sum;
    }
};

int main()
{
    Solution s;
    string column_title = "AB";
    int column_number = s.titleToNumber(column_title);
    cout << "The column number of " << column_title << " is " << column_number << endl;
    return 0;
}