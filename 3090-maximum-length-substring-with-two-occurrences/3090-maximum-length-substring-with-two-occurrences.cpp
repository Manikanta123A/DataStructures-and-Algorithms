class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> alpha(26, 0);

        int maxi = 0;
        int start = 0;

        for (int end = 0; end < s.size(); end++) {
            alpha[s[end]-'a']++;

            while (alpha[s[end]-'a'] > 2) {
                alpha[s[start]-'a']--;
                start++;
            }

            maxi = max(maxi, end - start + 1);
        }

        return maxi;
    }
};