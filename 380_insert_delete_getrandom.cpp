#include <iostream>
#include <unordered_map>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class RandomizedSet {
public:
    std::unordered_map<int, int> mp;
    std::vector<int> ans;

    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }
        ans.push_back(val);
        mp[val] = ans.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) != mp.end()) {
            int last = ans.back();
            int index = mp[val];
            ans[index] = last;
            mp[last] = index;
            ans.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        return ans[rand() % ans.size()];
    }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(5);
    bool param_2 = obj->insert(10);
    bool param_3 = obj->remove(5);
    int param_4 = obj->getRandom();

    std::cout << "Insertion success: " << param_1 << std::endl;
    std::cout << "Insertion success: " << param_2 << std::endl;
    std::cout << "Removal success: " << param_3 << std::endl;
    std::cout << "Random element: " << param_4 << std::endl;

    delete obj; // Don't forget to delete dynamically allocated memory

    return 0;
}
