#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> orgArr;
    int n;

public:
    Solution(vector<int> &nums) {
        orgArr = nums;
        n = orgArr.size();
    }

    vector<int> reset() {
        return orgArr;
    }

    vector<int> shuffle() {
        vector<int> shuffArr = orgArr;
        int last = n;
        for (int i = n - 1; i >= 0; i--) {
            int ptr = rand() % last;
            swap(shuffArr[i], shuffArr[ptr]);
            last--;
        }
        return shuffArr;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution solution(nums);

    cout << "Original Array: ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Shuffled Array: ";
    vector<int> shuffled = solution.shuffle();
    for (auto num : shuffled) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Reset Array: ";
    vector<int> reset = solution.reset();
    for (auto num : reset) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
