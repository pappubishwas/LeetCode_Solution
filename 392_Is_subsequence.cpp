#include <iostream>
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int j = 0;
        for (int i = 0; i < t.length() && j < s.length(); i++) {
            if (s[j] == t[i])
                j++;
        }
        return s.length() == j;
    }
};

int main() {
    Solution solution;
    std::string s = "abc";
    std::string t = "ahbgdc";
    bool result = solution.isSubsequence(s, t);
    std::cout << std::boolalpha << result << std::endl;  // This will print "true" in this example
    return 0;
}
