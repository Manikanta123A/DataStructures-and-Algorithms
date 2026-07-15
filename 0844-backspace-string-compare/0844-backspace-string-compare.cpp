class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string Ns = "";
        string Nt = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (!Ns.empty())
                    Ns.pop_back();
            } else {
                Ns.push_back(s[i]);
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#') {
                if (!Nt.empty())
                    Nt.pop_back();
            } else {
                Nt.push_back(t[i]);
            }
        }

        return Ns == Nt;
    }
};