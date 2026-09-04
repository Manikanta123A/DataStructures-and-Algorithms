class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // result[i] = minimum value from nums[i] to nums[n-1]
        vector<int> result(n);

        result[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            result[i] = min(nums[i], result[i + 1]);
        }

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            if (maxi - result[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};