class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        ans = 0

        for i in range(n):
            freq = [0] * 26

            for j in range(i, n):
                freq[ord(s[j]) - ord('a')] += 1

                counts = []

                for f in freq:
                    if f > 0:
                        counts.append(f)

                if len(set(counts)) == 1:
                    ans = max(ans, j - i + 1)

        return ans