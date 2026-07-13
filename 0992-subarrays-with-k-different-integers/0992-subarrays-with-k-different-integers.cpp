class Solution {
public:
    int subarray_atmost(vector<int>& nums, int k){
        unordered_map<int,int> um;
        int left =0,right=0,ans=0 ; 
        while ( right < nums.size()){
            um[nums[right]]++;
            while ( um.size() > k ){
                um[nums[left]]--;
                if(um[nums[left]] == 0) um.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int atmostk = subarray_atmost(nums,k);
        int atmostkm1 = subarray_atmost(nums,k-1);
        return atmostk - atmostkm1;
    }
};