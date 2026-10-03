class Solution:
    def longestValidParentheses(self, s: str) -> int:
        maxlen = 0
        left = right = 0

        # Left to right
        for ch in s:
            bit = int(ch == ')')

            if bit == 0:
                left += 1
            else:
                right += 1

            if left == right:
                maxlen = max(maxlen, 2 * right)
            elif right > left:
                left = right = 0

        left = right = 0

        # Right to left
        for ch in reversed(s):
            bit = int(ch == ')')

            if bit == 0:
                left += 1
            else:
                right += 1

            if left == right:
                maxlen = max(maxlen, 2 * left)
            elif left > right:
                left = right = 0

        return maxlen