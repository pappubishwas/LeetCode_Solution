#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return n > 0 && 1162261467 % n == 0;
    }
};

int main()
{
    Solution s;
    int num = 27;
    bool is_power_of_three = s.isPowerOfThree(num);
    if (is_power_of_three)
        cout << num << " is a power of three." << endl;
    else
        cout << num << " is not a power of three." << endl;
    return 0;
}