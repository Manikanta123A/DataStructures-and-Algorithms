class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size(),j,k;
        long res =0;
        stack<int> s; 
        for(int i =0; i<=n;i++){
            while ( !s.empty() && nums[s.top()] > (i==n ?-2e9: nums[i]) ){
                j=s.top();
                s.pop();
                k = s.empty() ? -1:s.top();
                res -= (long) nums[j]* (i-j)*(j-k);
            }
            s.push(i);
        }

        s = stack<int>();

        for(int i =0; i<=n;i++){
            while( !s.empty() && nums[s.top()] < (i==n? 2e9:nums[i])){
                j = s.top();
                s.pop();
                k = s.empty()? -1:s.top();
                res += (long) nums[j] * (i-j)*(j-k);
            }
            s.push(i);
        }
        return res;
       

    }
};