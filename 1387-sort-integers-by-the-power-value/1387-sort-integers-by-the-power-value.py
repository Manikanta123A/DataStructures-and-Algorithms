class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:

        dp = {1: 0}

        def power(x):
            if x in dp:
                return dp[x]

            original = x
            steps = 0

            while x not in dp:
                if x % 2 == 0:
                    x //= 2
                else:
                    x = 3 * x + 1

                steps += 1

            dp[original] = steps + dp[x]
            return dp[original]

        nums = []

        for x in range(lo, hi + 1):
            nums.append([power(x), x])

        nums.sort()

        return nums[k - 1][1]