class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size(); 

        vector<int> prefixSum(n,0);

        prefixSum[0] = stones[0];
        for(int i = 1; i<stones.size(); i++){
            prefixSum[i] = stones[i] + prefixSum[i-1];
        }
        long long dp = prefixSum[n-1];

        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefixSum[i] - dp);
        }

        return dp;
    }
};