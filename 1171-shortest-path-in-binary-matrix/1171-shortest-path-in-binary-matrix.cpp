class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;

        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        dist[0][0] = 1;

        pq.push({1, {0, 0}});

        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();

            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int nx = x +i;
                    int ny = y + j;

                    if(nx < n && nx >= 0 && ny < n && ny >= 0 && !grid[nx][ny] && 1 + d < dist[nx][ny]){
                        dist[nx][ny] = 1 + d;
                        pq.push({1 + d, {nx, ny}});
                    }
                }
            }
            
        }
        return dist[n-1][n-1] == 1e9 ? -1 : dist[n-1][n-1];

    }
};