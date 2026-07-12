class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> res(3,-1);
        int ans =0;
        for(int i=0; i<s.size();i++){
            res[s[i]-'a']= i;
            ans += min({res[0],res[1],res[2]})+1;
        }
        return ans;
    }
};