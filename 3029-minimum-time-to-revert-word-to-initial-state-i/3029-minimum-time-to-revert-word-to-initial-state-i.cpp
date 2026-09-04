class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size(); 

        for ( int t =1; ;t++){
            int removed = t*k; 
            if( t>=n){
                return t;
            }

            bool same = true; 
            for ( int i = removed; i<n; i++){
                if ( word[i] != word[i-removed]){
                    same = false; 
                    break;
                }
            }

            if ( same ) { 
                return t; 
            }
        }

    }
};