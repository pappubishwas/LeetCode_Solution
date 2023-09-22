class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        j = 0
        for i in range(len(t)):
            if j < len(s) and s[j] == t[i]:
                j += 1
        return len(s) == j

if __name__ == "__main__":
    solution = Solution()
    s = "abc"
    t = "ahbgdc"
    result = solution.isSubsequence(s, t)
    print(result)  # This will print True in this example
