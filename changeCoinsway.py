class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # Initialize a 2D DP array where dp[i][j] represents the number of combinations to make amount 'i'
        # using the first 'j' coins in the coins list.
        dp = [[0] * (len(coins) + 1) for _ in range(amount + 1)]
        
        # There's only one way to make amount 0 using any number of coins (i.e., not choosing any coin).
        dp[0] = [1] * (len(coins) + 1)

        # Fill the DP array using a bottom-up approach.
        for a in range(1, amount + 1):
            for i in range(len(coins) - 1, -1, -1):
                dp[a][i] = dp[a][i + 1]  # Exclude the current coin
                
                if a - coins[i] >= 0:
                    dp[a][i] += dp[a - coins[i]][i]  # Include the current coin
                    
        return dp[amount][0]  # Return the number of combinations to make the given amount using all coins.

def main():
    solution = Solution()
    amount = 5
    coins = [1, 2, 5]
    result = solution.change(amount, coins)
    print(f"Number of combinations to make {amount} cents: {result}")

if __name__ == "__main__":
    main()
