#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            ans |= (n & 1) << i;
            n >>= 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    uint32_t n = 0b00000010100101000001111010011100; // binary representation of 43261596
    uint32_t reversed = s.reverseBits(n);
    cout << "The bit-reversed form of " << n << " is " << reversed << endl;
    return 0;
}