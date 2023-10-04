#include <iostream>

class MyHashMap
{
public:
    vector<int> ans;
    MyHashMap() : ans(1000001, -1)
    {
    }

    void put(int key, int value)
    {
        ans[key] = value;
    }

    int get(int key)
    {
        return ans[key];
    }

    void remove(int key)
    {
        ans[key] = -1;
    }
};

int main()
{
    MyHashMap myHashMap;

    // Test cases
    myHashMap.put(1, 10);
    myHashMap.put(2, 20);
    myHashMap.put(3, 30);

    std::cout << "Value at key 1: " << myHashMap.get(1) << std::endl; // Output: 10
    std::cout << "Value at key 2: " << myHashMap.get(2) << std::endl; // Output: 20
    std::cout << "Value at key 3: " << myHashMap.get(3) << std::endl; // Output: 30

    myHashMap.remove(2);

    std::cout << "Value at key 2 after removal: " << myHashMap.get(2) << std::endl; // Output: -1

    return 0;
}
