#include <iostream>
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long int count = 0, j;
        for (int i = limit; i >= 0; i--) {
            if((n-i)<0) continue;
            if ((n - i) > (2 * limit))
                break;
            if (n - i >= limit)
                j = limit;
            else
                j = n - i;
            int minimum = n - i - j, maximum = j;
            count += ((maximum - minimum + 1));
        }
        return count;
    }
};
int main() {
    Solution solution;

    // Example usage:
    int n = 5; // Change the value of n as needed
    int limit = 2; // Change the value of limit as needed

    long long result = solution.distributeCandies(n, limit);

    std::cout << "Result for n=" << n << " and limit=" << limit << ": " << result << std::endl;

    return 0;
}
