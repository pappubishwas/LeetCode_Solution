#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=0,s,l,p;
        s=asteroids.size();
        vector<int>::iterator it;
 
        it = asteroids.begin();
        while(i<s-1){
             if((asteroids[i]>0 && asteroids[i+1]<0) || (asteroids[i]<0 && asteroids[i+1]>0)){
                 if(abs(asteroids[i])>abs(asteroids[i+1])){
                     asteroids.erase(it+i+1);
                     i--;
                     s--;
                 }else if(abs(asteroids[i])<abs(asteroids[i+1])) {
                     asteroids.erase(it+i);
                     i--;
                     s--;                     
                 }else{
                     asteroids.erase(it+i+1);
                     asteroids.erase(it+i);
                     i=i-1;
                     s=s-2;                     
                 }
             }else{
                 i++;
             }
        }
        return asteroids;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> result1 = sol.asteroidCollision(asteroids1);
    cout << "Result 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> asteroids2 = {8, -8};
    vector<int> result2 = sol.asteroidCollision(asteroids2);
    cout << "Result 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> result3 = sol.asteroidCollision(asteroids3);
    cout << "Result 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    // Add more test cases as needed

    return 0;
}
