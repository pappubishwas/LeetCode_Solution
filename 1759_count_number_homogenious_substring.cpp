#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        int c=1,n=s.size(),total=1,mod=1e9+7;
        char ch=s[0];
        for(int i=1;i<n;i++){
            if(s[i]==ch){
                c++;
                total+=c;
            }else{
                total+=1;
                c=1;
                ch=s[i];
            }
            total%=mod;
        }
        return total;
    }
};

int main() {
    Solution solution;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Result: " << solution.countHomogenous(s) << endl;
    return 0;
}
