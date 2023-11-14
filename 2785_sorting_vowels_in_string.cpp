#include <iostream>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowel;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
                vowel.push_back(s[i]);
            }
        }
        sort(vowel.begin(), vowel.end());
        int k = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
                s[i] = vowel[k];
                k++;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string input = "Hello, World!";
    string sortedVowels = sol.sortVowels(input);

    cout << "Original String: " << input << endl;
    cout << "String with sorted vowels: " << sortedVowels << endl;

    return 0;
}
