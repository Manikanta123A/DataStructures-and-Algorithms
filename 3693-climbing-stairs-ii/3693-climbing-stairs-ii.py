class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        n = len(costs) 
        if n==1: 
            return costs[0]+1
        dp = [0]* (n+1)
        dp[0] = 0 
        dp[1] = costs[0] + 1
        dp[2] = min ( dp[1]+ costs[1] + 1, dp[0]+costs[1] + 4)
        for i in range(3,n+1): 
            dp[i] = min ( 
                dp[i-1] + costs[i-1] + 1, 
                dp[i-2] + costs[i-1] + 4, 
                dp[i-3] + costs[i-1] + 9
            )
        return dp[n]