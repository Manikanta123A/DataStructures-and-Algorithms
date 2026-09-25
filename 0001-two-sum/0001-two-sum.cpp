class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> umap;
        for(int i=0; i< nums.size();i++){
            int first = nums[i];
            int second = target-first;
            if ( umap.find(second) != umap.end() ){
                ans.push_back(i);
                ans.push_back(umap[second]);
            }
            umap[first] = i;
        }
        return ans;
    }
};