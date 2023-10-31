#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
       int ans = 0;
       while (n / 5) {
           ans += n / 5;
           n /= 5;
       }
       return ans;
    }
};

int main() {
    Solution sol;
    int n = 25; // Example value for n
    int result = sol.trailingZeroes(n);
    cout << "Result: " << result << endl;
    return 0;
}
