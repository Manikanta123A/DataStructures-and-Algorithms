class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:

        hasher = {}

        for i in range(len(s)):
            if s[i] not in hasher:
                hasher[s[i]] = []

            hasher[s[i]].append(i)

        def get_interval(start):

            end = hasher[s[start]][-1]

            p = start

            while p <= end:

                c = s[p]

                if hasher[c][0] < start:
                    return None

                end = max(hasher[c][-1], end)

                p += 1

            return (start, end)

        candidates = []

        for i in range(len(s)):

            char = s[i]
            if i != hasher[char][0]:
                continue

            start = i

            candidate = get_interval(start)

            if candidate is not None:
                candidates.append(candidate)

        candidates.sort(key=lambda x: x[1])

        ans = []

        previous_end = -1

        for start, end in candidates:

            if start > previous_end:

                ans.append(s[start:end + 1])

                previous_end = end

        return ans