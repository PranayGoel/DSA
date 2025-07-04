class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto edge: times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        vector<int> dist(n+1, 1e9);

        dist[k] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int currdis = pq.top().first;
            pq.pop();

            if(currdis > dist[node]) continue;

            for(auto it: adj[node]){
                int adjnode = it.first;
                int wt = it.second;

                if(currdis + wt < dist[adjnode]){
                    dist[adjnode] = currdis + wt;
                    pq.push({dist[adjnode], adjnode});
                }

            }
        }
        int maxdis = 0;

        for(int i = 1; i <= n ;i++){
            if(dist[i] == 1e9) return -1;
            if(dist[i] > maxdis) maxdis = dist[i];
        }

        return maxdis;
    }   
};