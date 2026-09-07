class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows == s.size())
            return s;

        vector<string> rows(min(numRows, (int)s.size()), "");

        string res = "";

        int i = 0;
        bool flag = true;

        for (char c : s) {
            rows[i] += c;

            i += flag ? 1 : -1;

            if (i == numRows - 1 || i == 0)
                flag = !flag;
        }

        for (const auto& row : rows)
            res += row;

        return res;
    }
};