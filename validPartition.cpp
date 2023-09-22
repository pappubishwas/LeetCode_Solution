#include <iostream>
#include <vector>

class Solution
{
public:
    bool validPartition(std::vector<int> &nums)
    {

        int n = nums.size();
        if (n ==2 && nums[0]==nums[1])
            return true;
        else if(n==3 && nums[0]==nums[1]==nums[2])
        return true;    
        int c = 0, l = 0, r = 1;
        while (r < n)
        {
            if (nums[l] == nums[r])
            {
                c += 1;
                l += 2;
                r += 2;
            }
            else if (r + 1 < n && nums[r] - nums[l] == 1 && nums[r + 1] - nums[r] == 1)
            {
                c += 1;
                l += 3;
                r += 3;
            }
            else if(r+1<n && nums[l]==nums[r]==nums[r+1])
            {
                r++;
                l++;
            }
            
        }
        // if(n-l==1){
        //     if(nums[l]==nums[l-1] || (nums[l]-nums[l-1]==1 && num[l-1]-nums[])
        // }
        if (c > 1)
                return true;
        else        
        return false;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {1, 5, 11, 5}; // Replace with your input values
    bool isValidPartition = solution.validPartition(nums);

    if (isValidPartition)
    {
        std::cout << "The array can be partitioned into two subsets with equal sum." << std::endl;
    }
    else
    {
        std::cout << "The array cannot be partitioned into two subsets with equal sum." << std::endl;
    }

    return 0;
}
