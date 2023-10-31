#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lamda= [](int a, int b) {
            int countA = __builtin_popcount(a); //counting number of 1 bits in a integer
            int countB = __builtin_popcount(b);  
            return (countA == countB) ? a < b : countA < countB;
        };
        sort(arr.begin(), arr.end(), lamda);
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> sortedArray = sol.sortByBits(arr);

    cout << "Sorted Array: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
