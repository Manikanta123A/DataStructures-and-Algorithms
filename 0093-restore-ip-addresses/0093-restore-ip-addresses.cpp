class Solution {
public:
    vector<string> ans;

    bool valid(string part) {

        if (part.size() > 1 && part[0] == '0') {
            return false;
        }

        int num = stoi(part);
        return num <= 255;
    }

    void backtrack(string& s, int index, int parts, string current) {
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back(); 
                ans.push_back(current);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size()) {
                break;
            }

            string part = s.substr(index, len);

            if (!valid(part)) {
                continue;
            }

            backtrack(
                s,
                index + len,
                parts + 1,
                current + part + "."
            );
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        backtrack(s, 0, 0, "");
        return ans;
    }
};