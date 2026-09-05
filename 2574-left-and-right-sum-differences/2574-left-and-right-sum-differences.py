class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        answer = [0]*len(nums) 
        for i in range(len(nums)):
            answer[i] =abs(sum(nums[:i]) - sum(nums[i+1:]))
        return answer