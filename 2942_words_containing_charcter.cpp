#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) { 
            string s = words[i];
            if (s.find(x) != string::npos) 
                ans.push_back(i);
        }
        return ans; 
    }
};

int main() {
    // Sample usage of the findWordsContaining function
    Solution sol;

    // Sample vector of words
    vector<string> words = {"apple", "banana", "orange", "grape", "kiwi"};

    char characterToFind = 'a'; // Character to search for in the words

    // Using the findWordsContaining function
    vector<int> indices = sol.findWordsContaining(words, characterToFind);

    // Displaying the indices of words containing the specified character
    cout << "Indices of words containing '" << characterToFind << "':" << endl;
    for (int i : indices) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
