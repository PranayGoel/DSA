class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revgraph(n);
        vector<int> in(n, 0);

        for(int i = 0; i< n; i++){
            for(auto adjnode: graph[i]){
                revgraph[adjnode].push_back(i);
                in[i]++;
            }
        }

        queue<int> q;

        for(int i = 0; i< n; i++){
            if(in[i] == 0) q.push(i);
        }

        vector<int> safe;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for(auto adjnode: revgraph[node]){
                in[adjnode]--;
                if(in[adjnode] == 0){
                    q.push(adjnode);
                }
            }
        }

        sort(safe.begin(),safe.end());
        return safe;
    }

};