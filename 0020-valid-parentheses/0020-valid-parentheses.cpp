class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(char ch:s){
            cout<<ch<<endl;
            if ( ch == '{' || ch == '(' || ch == '['){
                s1.push(ch);
            }else{
                if (s1.empty() ) return false;
                char val = s1.top();
                s1.pop();
                if( (ch == '}' && val != '{') || (ch == ')' && val != '(') || (ch == ']' && val != '[')  ){
                    return false;
                }
                
            }
        }
        return s1.empty();
    }
};