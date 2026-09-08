
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int size1 = trust.size();
        vector<int> vec(n,0);
        for(int i=0;  i<size1; i++){
            vec[trust[i][0]-1] = -1;
            if (vec[trust[i][1]-1] != -1){
                vec[trust[i][1]-1] +=1;
            }
        }
        int i=0;
        int j = vec.size()-1;
        while(i<j){
            if(vec[i] == n-1){
                return i+1;
            }
            if(vec[j] == n-1){
                return j+1;
            }
            i++;
            j--;
        }
        if(i==j){
            if(vec[i]==n-1){
                return i+1;
            }
        }
        return -1;
    }
};