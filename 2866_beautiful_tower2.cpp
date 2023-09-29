#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findmax(std::vector<int> &maxHeights, int p)
    {
        int i = p;
        long long sum = 0, minel = maxHeights[p];
        while (i >= 0)
        {
            if (minel >= maxHeights[i])
            {
                sum += maxHeights[i];
                minel = maxHeights[i];
            }
            else
            {
                sum += minel;
            }
            i--;
        }
        i = p + 1;
        long long maxel = maxHeights[p];
        while (i < maxHeights.size())
        {
            if (maxel >= maxHeights[i])
            {
                sum += maxHeights[i];
                maxel = maxHeights[i];
            }
            else
            {
                sum += maxel;
            }
            i++;
        }
        return sum;
    }

    long long maximumSumOfHeights(std::vector<int> &maxHeights)
    {
        long long maxel = 0;
        for (int i = 0; i < maxHeights.size(); i++)
        {
            long long temp = findmax(maxHeights, i);
            maxel = std::max(maxel, temp);
        }
        return maxel;
    }
};
{
    Solution solution;

    // Example usage with a vector of maxHeights
    std::vector<int> maxHeights = {1, 2, 3, 4, 5};
    long long result = solution.maximumSumOfHeights(maxHeights);

    std::cout << "Maximum Sum of Heights: " << result << std::endl;

    return 0;
}
