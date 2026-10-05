class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)
        if len(stones) ==2 and stones[0] == 0 and stones[1] > 1:
            return False
        if len(stones)==2:
            return True
        stone_index = {stone: i for i, stone in enumerate(stones)}

        dp = [set() for _ in range(n)]

        if stones[1] != 1:
            return False

        dp[1].add(1)

        for i in range(1, n):
            for k in dp[i]:

                for jump in (k - 1, k, k + 1):
                    if jump <= 0:
                        continue

                    next_pos = stones[i] + jump

                    if next_pos in stone_index:
                        j = stone_index[next_pos]

                        if j == n - 1:
                            return True

                        dp[j].add(jump)

        return False