class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        maxi = upper
        mini = lower
        prefix = 0
        for i in range(len(differences)):
            prefix += differences[i] 
            maxi = min(maxi, upper - prefix)
            mini = max (mini, lower - prefix)
            if mini > maxi:
                return 0 
        return maxi-mini+1