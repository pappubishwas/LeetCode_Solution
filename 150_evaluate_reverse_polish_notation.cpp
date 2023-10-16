#include <iostream>
#include <stack>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &s)
    {
        int n = s.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != "-" && s[i] != "+" && s[i] != "*" && s[i] != "/")
            {
                    st.push(stoi(s[i]));
            }
            else if (st.size() >= 2)
            {
                int n1, n2;
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                if (s[i] == "-")
                {
                    st.push(n2 - n1);
                }
                else if (s[i] == "+")
                {
                    st.push(n2 + n1);
                }
                else if (s[i] == "*")
                {
                    st.push(n2 * n1);
                }
                else
                {
                    st.push(n2 / n1);
                }
            }
        }
        return st.top();
    }
};

int main()
{
    Solution solution;
    vector<string> s = {"2", "1", "+", "3", "*"}; // Example input, modify as needed
    cout << "Result: " << solution.evalRPN(s) << endl;
    return 0;
}
