class Solution {
public:
    string convert(string s, int n) {
        string str;
        if (n==1){
            return s;
        }
        for(int i=1;i <= n;i++){
            int a =i-1;
            if( i == 1 || i == n){
                while (a < s.size()){
                str = str + s[a];
                a = a + n-1 + n-1;
                }
            }else{
                int sa =0;
                while(a < s.size()){
                    if(sa%2 == 0){
                        str = str + s[a];
                        a = a+  (n-i) + (n-i-1) +1;
                    }else{
                        str = str+ s[a];
                        a = a + (i-2) +i;
                    }
                    sa++;
                }
            }
            
        }
        return str;
    }
};