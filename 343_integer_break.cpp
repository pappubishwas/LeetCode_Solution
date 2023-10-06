#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        int product = 1, rem, res = 0, m;
        for (int i = 2; i <= n; i++)
        {
            m = n / i;
            rem = n % i;
            product = pow(m + 1, rem) * pow(m, i - rem);
            res = std::max(res, product);
        }
        return res;
    }
};

int main()
{
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    Solution obj;
    int result = obj.integerBreak(n);

    std::cout << "Maximum product after breaking the integer: " << result << std::endl;

    return 0;
}
