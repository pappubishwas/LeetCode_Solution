#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hb, vector<int>& vb) {
        int res = 0;
        sort(hb.begin(), hb.end());
        sort(vb.begin(), vb.end());
        int hbel = 0, currhb = 1, vbel = 0, currvb = 1;

        for (int i = 1; i < hb.size(); i++) {
            if (abs(hb[i - 1] - hb[i]) == 1) {
                currhb++;
            } else {
                hbel = max(hbel, currhb + 1);
                currhb = 1;
            }
        }
        hbel = max(hbel, currhb + 1);

        for (int i = 1; i < vb.size(); i++) {
            if (abs(vb[i - 1] - vb[i]) == 1) {
                currvb++;
            } else {
                vbel = max(vbel, currvb + 1);
                currvb = 1;
            }
        }
        vbel = max(vbel, currvb + 1);

        res = min(hbel, vbel);
        m = min(n + 1, m + 1);
        res = min(res, m);
        res = pow(res, 2);

        return res;
    }
};

int main() {
    Solution sol;
    int n = 3; // Example value for n
    int m = 4; // Example value for m

    vector<int> horizontalBars = {2, 3}; // Example horizontal bars
    vector<int> verticalBars = {1}; // Example vertical bars

    int maxArea = sol.maximizeSquareHoleArea(n, m, horizontalBars, verticalBars);
    cout << "Maximized square hole area: " << maxArea << endl;

    return 0;
}
