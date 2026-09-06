class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        freq = Counter(nums) 
        for count in freq.values():
            if count >= 3:
                return False
        return True