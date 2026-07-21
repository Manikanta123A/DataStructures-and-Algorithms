class Solution {
public:
    int myAtoi(string s) {
        int sum =0;
        bool neg = false;
        for(int i=0; i< s.size(); i++){
            
            if(s[i] == '-'){
                if(i!=0 && s[i-1] != ' '){
                    break;
                }else{
                    neg = true;
                }
            }
            else if(s[i] == '+'){
                if(i!=0 && s[i-1] !=' '){
                    break;
                }else{continue;}
            }
            else if((sum == 0 && s[i] == '0')){
                continue;
            }
            else if (s[i] == ' '){
                if(i!=0 && s[i-1] != ' '){
                    break;
                }else{continue;}
            }
            else if(s[i] >=  '0' && s[i] <= '9'){
                int digit = s[i] - '0';
                if((sum > (INT_MAX - digit)/10 )){
                    return neg? INT_MIN: INT_MAX;
                }
                sum = sum*10 + (s[i] - '0');
            }
            else{
                break;
            }
        }
        if(neg){
            return -sum;
        }
        return sum;
    }
};