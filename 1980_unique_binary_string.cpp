#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;

        for (int i = 0; i < nums.size(); ++i) {
            result += (nums[i][i] == '0' ? '1' : '0');
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> binaryStrings = {"01", "10"}; // Example input: replace this with your test cases
    string result = sol.findDifferentBinaryString(binaryStrings);

    cout << "The different binary string is: " << result << endl;

    return 0;
}
