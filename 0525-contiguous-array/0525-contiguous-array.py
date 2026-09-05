class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        first_seen = {0:-1}
        balance = 0
        max_len = 0

        for i in range(len(nums)):
            balance += 1 if nums[i] == 1 else -1

            if balance in first_seen:
                max_len = max(max_len, i - first_seen[balance])
            else:
                first_seen[balance] = i

        return max_len