class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> s;
        for(int i =0; i<asteroids.size(); i++){
            bool does = false;
            while (!s.empty() && !(asteroids[i] > 0)){
                if ( s.top() > 0 ){
                    int val = s.top();
                    if( s.top() == abs(asteroids[i]) ){
                        s.pop();
                        does = true;
                        break;
                    }else if( s.top() > abs(asteroids[i])) {
                        break;
                    }else{
                        s.pop();
                    }
                }else{
                    s.push(asteroids[i]);
                    break;
                }
            }
            if( asteroids[i] > 0 ) s.push(asteroids[i]);
            if(s.empty() && !does) s.push(asteroids[i]);
            
        }
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};