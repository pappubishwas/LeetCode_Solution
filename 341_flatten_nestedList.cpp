#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    queue<int> q;
    void flatten(vector<NestedInteger> &nestedList){
        int n=nestedList.size();
        for(int i=0;i<n;i++){
            NestedInteger& curr=nestedList[i];
            if(curr.isInteger())
                q.push(curr.getInteger());
            else
                flatten(curr.getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    int next() {
        int num=q.front();
        q.pop();
        return num;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

// Example of usage:
int main() {
    // Create and populate a nested list for testing
    NestedInteger n1, n2, n3, n4;
    n1 = NestedInteger();
    n2 = NestedInteger();
    n3 = NestedInteger();
    n4 = NestedInteger();
    n1 = 1;
    n2 = 2;
    n3 = 3;
    n4 = 4;
    vector<NestedInteger> nestedList;
    nestedList.push_back(n1);
    nestedList.push_back(n2);
    nestedList.push_back(n3);
    nestedList.push_back(n4);

    NestedIterator i(nestedList);
    while (i.hasNext()) {
        cout << i.next() << " ";
    }
    cout << endl;

    return 0;
}
