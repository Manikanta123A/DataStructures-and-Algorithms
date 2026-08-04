class Solution {
public:

    void combine(string digits ,unordered_map<char,string> um , string s, vector<string> &ans, int idx){
        
        if (idx == digits.size()){
            ans.push_back(s);
            return;
        }
        for(int j =0; j<um[digits[idx]].size();j++){
            combine(digits, um, s+um[digits[idx]][j],ans,idx+1);
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans; 
        if(digits.size() == 0){
            return ans;
        }
        unordered_map<char,string> um;
        um['2'] = "abc";
        um['3'] = "def";
        um['4'] = "ghi";
        um['5'] = "jkl";
        um['6'] = "mno";
        um['7'] = "pqrs";
        um['8'] = "tuv";
        um['9'] = "wxyz"; 

        
        combine(digits, um , "",ans,0);
        return ans;
    }
};