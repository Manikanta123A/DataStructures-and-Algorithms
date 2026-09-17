class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)

        best = [float('inf')] * (n + 1)

        prefix = {0: 0}
        curr_sum = 0

        answer = float('inf')

        for i in range(1, n + 1):
            curr_sum += arr[i - 1]
            best[i] = best[i - 1]
            needed = curr_sum - target
            if needed in prefix:
                start = prefix[needed]
                length = i - start
                if best[start] != float('inf'):
                    answer = min(answer, length + best[start])
                best[i] = min(best[i], length)
            prefix[curr_sum] = i

        return -1 if answer == float('inf') else answer