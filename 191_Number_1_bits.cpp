#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & 1)
                count++;
            n = n >> 1;
        }
        return count;
    }
};

int main()
{
    Solution s;
    uint32_t n = 0b11010101010101010101010101010101; // binary representation of 1431655765
    int count = s.hammingWeight(n);
    cout << "The number of 1 bits in " << n << " is " << count << endl;
    return 0;
}