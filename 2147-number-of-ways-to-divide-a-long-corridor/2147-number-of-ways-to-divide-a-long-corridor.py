class Solution:
    def numberOfWays(self, corridor: str) -> int:
        MOD = 10**9 + 7

        seats = corridor.count('S')

        if seats < 2 or seats % 2 != 0:
            return 0

        ans = 1
        seats = 0
        gap = 0

        for ch in corridor:
            if ch == 'S':
                seats += 1

                if seats > 2 and seats % 2 == 1:
                    ans = ans * (gap + 1) % MOD

                gap = 0
            elif seats >= 2 and seats % 2 == 0:
                gap += 1

        return ans