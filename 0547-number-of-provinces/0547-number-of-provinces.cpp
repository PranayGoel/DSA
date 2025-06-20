class Solution {
public:
    void dfs(int node, vector<int> adjList[], vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adjList[node]) {
            if (!vis[it]) {
                dfs(it, adjList, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n];

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjList, vis);
            }
        }

        return cnt;
    }
};
