class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        ans = nums[0] 
        newl = nums[1:]
        newl.sort() 
        return ans + newl[0] + newl[1]