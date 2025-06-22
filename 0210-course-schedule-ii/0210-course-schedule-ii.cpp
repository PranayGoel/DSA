class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];

        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        vector<int> indegree(numCourses,0);

        for(int i = 0; i< numCourses; i++){
            for(auto adjnode: adj[i]){
                indegree[adjnode]++;
            }
        }

        queue<int> q;

        for(int i = 0; i< numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto adjnode: adj[node]){
                indegree[adjnode]--;
                if(indegree[adjnode] == 0){
                    q.push(adjnode);
                }
            }
        }

        if(numCourses == topo.size()) return topo;
        else return vector<int>{};
    }
};