#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas = 0, total_cost = 0;
        int curr_gas = 0, starting_point = 0;
        for (int i = 0; i < n; i++) {
            //these two variable are to check if no case is possible
            total_gas += gas[i];
            total_cost += cost[i];
            //for checking the total present gas at index i
            curr_gas += gas[i] - cost[i];
            if (curr_gas < 0) {
                //there is a breakdown....so we will start from the next point or index
                starting_point = i + 1;
                //reset our fuel
                curr_gas = 0;
            }
        }
        return (total_gas < total_cost) ? -1 : starting_point;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int result = sol.canCompleteCircuit(gas, cost);
    cout << "Result: " << result << endl;
    return 0;
}
