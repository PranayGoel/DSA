class Solution {
public:
    bool check_bfs(int start, int n, vector<vector<int>>& graph,vector<int>& vis){
        
        // 0,1
        vis[start] = 0;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();

            q.pop();
            //if(graph[node].size() == 0) return false;
            for(auto adjnode : graph[node]){
                if(vis[adjnode] == -1){
                    vis[adjnode] = !vis[node];
                    q.push(adjnode);

                }
                
                else if(vis[adjnode] == vis[node]) 
                    return false;
            }
        }

        return true;
    }

    bool check_dfs(int node, int color, vector<vector<int>>& graph,vector<int>& vis){
        vis[node] =  color;

        for(auto adjnode: graph[node]){
            if(vis[adjnode] == -1){
                if(check_dfs(adjnode, !color, graph, vis)== false) return false;
            }
            else if(vis[adjnode] == color)
                return false;
        }

        return true;
    }



    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> vis(n, -1);
        
        for(int i = 0; i< n; i++){
            if(vis[i] == -1){
                //if(check_bfs(i, n, graph, vis) == false) return false
                if(check_dfs(i, 0, graph, vis) == false)
                    return false;
            }
        }

        return true;

    }
};