class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0

        for left in range(n):
            product = 1
            gcd = 0
            lcm = 1

            for right in range(left, n):
                x = nums[right]

                product *= x
                gcd = math.gcd(gcd, x)
                lcm = math.lcm(lcm, x)

                if product == gcd * lcm:
                    res = max(res, right - left + 1)

        return res
