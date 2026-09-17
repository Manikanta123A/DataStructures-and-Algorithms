class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        n = len(beans)
        beans.sort()

        prefix_sum = [0] * (n+1)

        for i in range(len(beans)):
            prefix_sum[i+1] = prefix_sum[i] + beans[i]
        
        cost = float('inf')

        for i in range(len(beans)):
            curr_cost = prefix_sum[i] + (prefix_sum[n] - prefix_sum[i]) - beans[i] * (n-i)
            cost = min(cost,curr_cost)
        
        return cost