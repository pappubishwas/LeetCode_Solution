#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> freq(26, 0); // Track the last index of occurrence for each element
        for (int i = 0; i < s.size(); ++i)
            freq[s[i] - 'a']++;

        stack<char> st;               // Monotonic stack to maintain increasing order of chars
        vector<bool> seen(26, false); // Track already included elements
        for (int i = 0; i < s.size(); ++i)
        {
            if (seen[s[i] - 'a'])
            { // Don't process already included char
                freq[s[i] - 'a']--;
                continue;
            }
            while (!st.empty() && st.top() > s[i] && freq[st.top() - 'a'] > 0)
            { // Pop all possible larger chars
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i] - 'a'] = true;
            freq[s[i] - 'a']--;
        }
        string ans = "";
        while (!st.empty())
        { // Build the answer string
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution solution;
    string input = "bcabc";
    string result = solution.removeDuplicateLetters(input);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
