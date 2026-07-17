class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        priority_queue<int> pq;
        for(int i =0; i<hand.size(); i++){
            pq.push(hand[i]);
        }

        while ( !pq.empty() ){
            vector<int> remain;
            int count =1; 
            int val = pq.top();
            pq.pop();
            while (!pq.empty() && count < k){
                int pop = pq.top();
                pq.pop();
                
                if( pop+1 == val){
                   
                    count++;
                    val = pop;
                }else{
                    
                    remain.push_back(pop);
                   
                }
            }

            if (count != k) {
                return false;
            }
           
            while( !remain.empty() ){
                
                pq.push(remain.back());
                remain.pop_back();
            }
        }
        return true;
    }
};