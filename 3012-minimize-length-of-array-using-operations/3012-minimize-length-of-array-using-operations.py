class Solution:
    def minimumArrayLength(self, nums: List[int]) -> int:
        Min_el = min(nums)
        count = 0
        for val in nums:
            if val == Min_el:
                count+=1
        
        if count == 1:
            return 1
        
        for val in nums:
            if val% Min_el != 0:
                return 1
        

        return (count+1)//2