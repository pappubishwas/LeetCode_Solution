#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &h)
    {
        int area = 0, l = 0, r = h.size() - 1;
        while (l < r)
        {
            int temp = min(h[l], h[r]);
            int base = r - l;
            area = max(area, temp * base);
            if (h[l] < h[r])
                l++;
            else
                r--;
        }
        return area;
    }
};

int main()
{
    Solution solution;

    // Example vector of heights
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = solution.maxArea(heights);

    cout << "Maximum Area: " << result << endl;

    return 0;
}
