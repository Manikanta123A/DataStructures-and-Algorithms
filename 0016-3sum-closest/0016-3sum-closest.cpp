class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int min_diff = INT_MAX;
        for (int i=0; i<nums.size(); i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while ( j<k){
                int value = nums[i]+nums[j]+nums[k];
                int curr_diff = abs(value - target);

                if (curr_diff < min_diff){
                    min_diff = curr_diff;
                    ans = value;
                }
                if (value < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};