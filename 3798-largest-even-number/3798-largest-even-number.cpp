class Solution {
public:
    string largestEven(string s) {
        int pos = s.rfind('2');

        if (pos == string::npos)
            return "";

        return s.substr(0, pos + 1);
    }
};