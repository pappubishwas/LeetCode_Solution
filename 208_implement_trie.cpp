#include <iostream>
#include <unordered_map>
#include <string>
#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
    std::unordered_map<std::string, int> mp;

    Trie() {}

    void insert(std::string word) {
        mp[word] = 1;
    }

    bool search(std::string word) {
        return mp.find(word) != mp.end();
    }

    bool startsWith(std::string prefix) {
        int n = prefix.size();
        for (auto it : mp) {
            std::string t = it.first;
            if (t.size() >= n && t.substr(0, n) == prefix) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    bool param_2 = obj->search("apple");
    bool param_3 = obj->startsWith("app");

    std::cout << "Search for 'apple': " << param_2 << std::endl;
    std::cout << "Starts with 'app': " << param_3 << std::endl;

    delete obj; // Don't forget to delete dynamically allocated memory

    return 0;
}
