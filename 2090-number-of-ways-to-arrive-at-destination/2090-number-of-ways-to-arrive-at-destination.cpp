class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> dist(n, 1e18); // Use long long
        vector<int> ways(n, 0);

        // Priority queue stores {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long currdist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (currdist > dist[node]) continue;

            for (auto& it : adj[node]) {
                int adjnode = it.first;
                long long wt = it.second;

                if (currdist + wt < dist[adjnode]) {
                    dist[adjnode] = currdist + wt;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                }
                else if (currdist + wt == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
