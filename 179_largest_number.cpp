#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b)
{
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}
class Solution {
public:
    string largestNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        string ans = "";
        for(int i = 0;i<arr.size();i++)
        ans+=to_string(arr[i]);
        if(ans[0]=='0') return "0";
        return ans; 
    }
};
int main() {
    // Example usage of the Solution class
    Solution solution;
    vector<int> arr = {3, 30, 34, 5, 9}; // Example input array

    // Calling the largestNumber function to find the largest possible number
    string largest_num = solution.largestNumber(arr);

    // Output the result
    cout << "Largest Number: " << largest_num << endl;

    return 0;
}
