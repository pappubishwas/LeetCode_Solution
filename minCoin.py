class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp=[amount+1]*(amount+1)
        dp[0]=0

        for a in range(1,amount+1):
            for c in coins:
                if a-c>=0:
                    dp[a]=min(dp[a],1+dp[a-c])

        return dp[amount] if dp[amount] != amount+1 else -1

def main():
    solution = Solution()
    coins = [1, 2, 5]
    amount = 11
    result = solution.coinChange(coins, amount)
    print(f"Minimum number of coins needed to make {amount} cents: {result}")

if __name__ == "__main__":
    main()
