#include <iostream>
#include <string>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int nu, int de) {
        string st = "", s = "";
        if ((nu > 0 && de < 0) || ((nu < 0 && de > 0)))
            s += "-";
        long long num = labs(nu); // using labs for long long absolute value
        long long den = labs(de); // using labs for long long absolute value
        long long res = num / den; // using long long
        long long rem = num % den; // using long long
        st += to_string(res);
        
        if (rem == 0)
            return s + st;
        st += ".";
        unordered_map<long long, int> mp; // using long long in unordered_map
        int i = st.size();
        while (i < 10000 && rem != 0) {
            if (mp[rem] != 0) {
                st.insert(mp[rem], "(");
                st += ")";
                return s + st;
            }
            mp[rem] = i;
            rem *= 10;
            res = rem / den;
            st += to_string(res);
            rem %= den;
            i++;
        }
        return s + st;
    }
};

int main() {
    Solution sol;
    int nu = 1;
    int de = 2;
    string result = sol.fractionToDecimal(nu, de);
    cout << "Result: " << result << endl;
    return 0;
}
