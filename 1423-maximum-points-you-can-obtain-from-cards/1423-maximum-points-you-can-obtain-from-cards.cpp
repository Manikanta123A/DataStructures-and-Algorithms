class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix(n,0);
        prefix[0] = cardPoints[0];
        for(int i =1; i<n;i++){
            prefix[i] = prefix[i-1] + cardPoints[i];
        }
        if (k == n){
            return prefix[n-1];
        }
        int start =0; 
        int currSum =prefix[n-k-1];
        int valid = currSum;
        for(int end =n-k; end<n;end++){
            currSum += cardPoints[end];
            currSum-= cardPoints[start];
            start++;
            valid = min(valid, currSum);
        }
        return prefix[n-1]-valid;

    }
};