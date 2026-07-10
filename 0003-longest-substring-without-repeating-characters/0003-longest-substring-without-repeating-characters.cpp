class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> result(128,0);
        int start = 0;
        int ans = 0;
        for(int i =0; i<s.size();i++){
            while (result[s[i]] != 0){
                result[s[start]]--;
                start++;
            }
            result[s[i]]=1;
            ans = max(ans, i-start+1);
        }
        return ans;
    }
};