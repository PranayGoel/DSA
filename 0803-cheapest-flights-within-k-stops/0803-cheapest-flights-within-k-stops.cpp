class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>> adj[n];

        for(auto it: flights){
            int s = it[0];
            int d = it[1];
            int p = it[2];
            adj[s].push_back({d, p});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // stops, node, cost
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto iter: adj[node]){
                int adjnode = iter.first;
                int wt = iter.second;

                if(cost + wt < dist[adjnode] && stops <= k){
                    dist[adjnode] = cost + wt;
                    q.push({stops+1, {adjnode, cost+wt}});
                }

            }
        }


        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};