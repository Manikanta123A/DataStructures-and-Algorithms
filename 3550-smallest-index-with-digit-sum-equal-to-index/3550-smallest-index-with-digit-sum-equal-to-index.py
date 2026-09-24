class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            digits = list(map(int, str(nums[i])))
            if sum(digits) == i:
                return i
        return -1