class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> um;
        um[0] = 1;
        int prefix = 0 ;
        int ans =0;
        for(int i =0; i<nums.size();i++){
            prefix += nums[i];

            if(um.count(prefix-goal)){
                ans+= um[prefix-goal];
            }
            um[prefix]++;
        }
        return ans;
    }
};