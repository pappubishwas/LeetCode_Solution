#include <iostream>
#include <vector>
#include <set>
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
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        curr = {};
        backtrack(ans, curr, nums);

        // Converting the 2D vector to set to remove duplicates
        set<vector<int>> mySet(ans.begin(), ans.end());

        // Converting the set of vectors back to a 2D vector
        vector<vector<int>> uniqueVector(mySet.begin(), mySet.end());

        return uniqueVector;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = solution.permuteUnique(nums);

    cout << "Unique Permutations:" << endl;
    for (const vector<int>& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
