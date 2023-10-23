#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        while(n>0){
            if(n==1) return true;
            if(n%4==0) n/=4;
            else return false;
        }
        return false;
    }
};

int main() {
    Solution solution;
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    if (solution.isPowerOfFour(num)) {
        std::cout << num << " is a power of 4." << std::endl;
    } else {
        std::cout << num << " is not a power of 4." << std::endl;
    }
    return 0;
}
