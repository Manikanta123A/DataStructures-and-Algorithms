class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;

        for(auto& p: prerequisites){
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for(int i =0; i<numCourses;i++){
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int visited = 0;

        while (!q.empty()){
            int course = q.front();
            ans.push_back(course);
            q.pop();
            visited++;
            for(int next:graph[course]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }

        if (visited==numCourses){
            return ans;
        }
        return {};
    }
};