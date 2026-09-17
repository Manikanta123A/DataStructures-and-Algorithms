class Solution:
    def longestBalanced(self, s: str) -> int:
        ans = 1

        # One character
        count = 1

        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                count += 1
            else:
                count = 1

            ans = max(ans, count)

        # Two characters
        def two_chars(a, b, forbidden):
            best = 0
            count_a = 0
            count_b = 0
            seen = {0: -1}

            for i, ch in enumerate(s):

                if ch == forbidden:
                    count_a = 0
                    count_b = 0
                    seen = {0: i}
                    continue

                if ch == a:
                    count_a += 1
                else:
                    count_b += 1

                diff = count_a - count_b

                if diff in seen:
                    best = max(best, i - seen[diff])
                else:
                    seen[diff] = i

            return best

        ans = max(ans, two_chars('a', 'b', 'c'))
        ans = max(ans, two_chars('b', 'c', 'a'))
        ans = max(ans, two_chars('a', 'c', 'b'))

        # Three characters
        seen = {(0, 0): -1}
        a = b = c = 0

        for i, ch in enumerate(s):
            if ch == 'a':
                a += 1
            elif ch == 'b':
                b += 1
            else:
                c += 1

            key = (a - b, a - c)

            if key in seen:
                ans = max(ans, i - seen[key])
            else:
                seen[key] = i

        return ans