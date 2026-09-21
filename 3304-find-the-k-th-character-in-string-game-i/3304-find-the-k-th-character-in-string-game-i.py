class Solution:
    def kthCharacter(self, k: int) -> str:
        shifts = 0
        length = 1

        while length < k:
            length *= 2

        while length > 1:
            half = length // 2

            if k > half:
                k -= half
                shifts += 1

            length = half

        return chr(ord('a') + shifts % 26)