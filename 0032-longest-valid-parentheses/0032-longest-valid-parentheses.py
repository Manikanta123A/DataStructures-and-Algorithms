class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stacker = [-1]
        maxlen = 0

        for i in range(len(s)):
            if s[i] == '(':
                stacker.append(i)

            else:
                stacker.pop()

                if not stacker:
                    stacker.append(i)
                else:
                    length = i - stacker[-1]
                    maxlen = max(maxlen, length)

        return maxlen