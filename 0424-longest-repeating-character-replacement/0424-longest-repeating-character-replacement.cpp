class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> store(26,0);
        int start =0;
        int maxAlpha =0;
        for(int i =0;i<s.size();i++){
            store[s[i]-'A']++;
            maxAlpha = max(store[s[i]-'A'],maxAlpha);
            if ((i-start+1)-maxAlpha > k ){
                store[s[start]-'A']--;
                start++;
            }

        }

        return (int)s.size()-start;
    }
};