#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        int i = 1;
        while (i <= n) {
            int temp = i % 2;
            temp += ans[i / 2];
            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 5; // You can change this to any non-negative integer.
    vector<int> result = solution.countBits(n);

    cout << "Count of bits for numbers from 0 to " << n << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
