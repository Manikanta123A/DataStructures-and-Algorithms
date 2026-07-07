class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ple(n,-1);
        vector<int> nle(n,n);

        for(int i =0; i<n;i++){
            while ( !s.empty() && nums[s.top()] > nums[i]){
                s.pop();
            }
            if(!s.empty()){
                ple[i] = s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i = n-1; i>=0; i--){
            while ( !s.empty() && nums[s.top()] >= nums[i]){
                s.pop();
            }
            if(!s.empty()){
                nle[i] = s.top();
            }
            s.push(i);
        }

        long long ans = 0;
        const int MOD = 1e9 + 7;
        for(int i =0; i<n; i++){
            long long l = i - ple[i];
            long long r = nle[i] - i; 
            ans =(ans + r*l%MOD *nums[i]) % MOD;
        }

        return ans;



    }
};