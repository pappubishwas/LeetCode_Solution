#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        long dvd = abs(dividend), dvs = abs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs)
        {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd)
            {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};

int main()
{
    Solution solution;

    int dividend = 10; // Replace with your desired dividend value.
    int divisor = 3;   // Replace with your desired divisor value.

    int result = solution.divide(dividend, divisor);
    std::cout << "Result of division: " << result << std::endl;

    return 0;
}
