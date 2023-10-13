#include <iostream>
#include <vector>

// Definition for the MountainArray class (simulated)
class MountainArray {
public:
    int get(int index) {
        // Simulated implementation for demonstration
        return arr[index];
    }

    int length() {
        return arr.size();
    }

    // Constructor to initialize the mountain array
    MountainArray(std::vector<int>& elements) : arr(elements) {}

private:
    std::vector<int> arr;
};

class Solution
{
public:
    int peakIndexInMountainArray(MountainArray &mountainArr)
    {
        int n = mountainArr.length();

        int l = 0;
        int r = n - 1;

        while (l < r)
        {

            int mid = l + (r - l) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    int binarySearch(MountainArray &mountainArr, int l, int r, int target)
    {

        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return -1;
    }

    int reverseBinarySearch(MountainArray &mountainArr, int l, int r, int target)
    {
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) > target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();

        int peakIndex = peakIndexInMountainArray(mountainArr);

        int idx = binarySearch(mountainArr, 0, peakIndex, target);

        if (idx == -1)
        {
            return reverseBinarySearch(mountainArr, peakIndex, n - 1, target);
        }

        return idx;
    }
};

int main() {
    // Create a mountain array with elements [1, 2, 3, 4, 5, 3, 1]
    std::vector<int> elements = {1, 2, 3, 4, 5, 3, 1};
    MountainArray mountainArr(elements);

    Solution solution;

    int target = 3;
    int result = solution.findInMountainArray(target, mountainArr);

    if (result != -1) {
        std::cout << "The target " << target << " is found at index " << result << std::endl;
    } else {
        std::cout << "The target " << target << " is not found in the mountain array." << std::endl;
    }

    return 0;
}
