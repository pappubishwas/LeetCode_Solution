#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }
        int parent = kthGrammar(n - 1, (k / 2) + (k % 2));
        if (k % 2 == 0) {
            return (parent == 1) ? 0 : 1;
        } else {
            return parent;
        }
    }
};

// Main function for testing the solution
int main() {
    Solution sol;
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    int result = sol.kthGrammar(n, k);
    cout << "Result: " << result << endl;
    return 0;
}
