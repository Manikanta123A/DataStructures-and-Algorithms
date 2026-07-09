class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c - '0') {
                st.pop();
                k--;
            }
            st.push(c - '0');
        }

        while (k > 0) {
            st.pop();
            k--;
        }

        string res;

        while (!st.empty()) {
            res.push_back(st.top() + '0');
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0;
        while (i < res.size() && res[i] == '0')
            i++;

        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};