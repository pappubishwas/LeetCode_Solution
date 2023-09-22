#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums) {
        if (0 == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            backtrack(ans, curr, temp);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        curr = {};
        backtrack(ans, curr, nums);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> permutations = obj.permute(nums);

    for (const auto& permutation : permutations) {
        cout << "[";
        for (int i = 0; i < permutation.size(); i++) {
            cout << permutation[i];
            if (i < permutation.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
