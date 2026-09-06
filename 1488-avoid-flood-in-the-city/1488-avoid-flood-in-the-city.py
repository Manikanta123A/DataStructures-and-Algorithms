class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)
        ans = [1] * n

        filled = {}

        dried = SortedList()

        for i in range(n):
            if rains[i] == 0:
                dried.add(i)
                continue

            lake = rains[i]
            ans[i] = -1

            if lake in filled:
                pos = dried.bisect_right(filled[lake])

                if pos == len(dried):
                    return []

                dry_day = dried[pos]
                ans[dry_day] = lake
                dried.pop(pos)

            filled[lake] = i

        return ans
