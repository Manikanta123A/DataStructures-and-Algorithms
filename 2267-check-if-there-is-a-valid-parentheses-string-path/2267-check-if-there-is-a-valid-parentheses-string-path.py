class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])

        length = (m - 1) + (n - 1) + 1

        if length % 2 == 1:
            return False

        if grid[0][0] == ')':
            return False
        if grid[-1][-1] == '(':
            return False

        dp = [[[False] * (length + 1) for _ in range(n)]
              for _ in range(m)]
        dp[0][0][1] = True

        for i in range(m):
            for j in range(n):

                if i == 0 and j == 0:
                    continue

                for bal in range(length + 1):

                    if grid[i][j] == '(':
                        if bal > 0:
                            dp[i][j][bal] = (
                                (i > 0 and dp[i-1][j][bal-1]) or
                                (j > 0 and dp[i][j-1][bal-1])
                            )

                    else:  
                        if bal < length:
                            dp[i][j][bal] = (
                                (i > 0 and dp[i-1][j][bal+1]) or
                                (j > 0 and dp[i][j-1][bal+1])
                            )

        return dp[m-1][n-1][0]