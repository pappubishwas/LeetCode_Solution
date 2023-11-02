#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> seen(n, false);
        int ans = 0;
        for (int num = 2; num < n; num++) {
            if (seen[num]) continue;
            ans++;
            for (long mult = (long)num * num; mult < n; mult += num)
                seen[mult] = true;
        }
        return ans;
    }
};

// Example usage of the Solution class
int main() {
    int n = 10; // Example value for n, you can change it to any positive integer

    Solution solution;
    int result = solution.countPrimes(n);

    cout << "Number of primes less than " << n << " is: " << result << endl;

    return 0;
}
