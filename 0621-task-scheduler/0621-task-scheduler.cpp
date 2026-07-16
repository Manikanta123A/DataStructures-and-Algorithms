class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> mp(26,0);
        for(char i:tasks){
            mp[i-'A']++;
        }
        for(int i = 0; i<26;i++ ){
            if (mp[i])
            pq.push(mp[i]);
        }
        int time =0; 
        while (!pq.empty()){
            vector<int> remain;
            int cycle = n+1;
            while ( cycle && !pq.empty()){
                int maxFreq = pq.top();
                pq.pop();
                if(maxFreq > 1){
                    remain.push_back(maxFreq-1);
                }
                cycle--;
                time++;
            }
            for(int count:remain){
                pq.push(count);
            }
            if(pq.empty()){
                break;
            }
            time+=cycle;
        }
        return time;

    }
};