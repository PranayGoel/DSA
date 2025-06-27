class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;

        queue<pair<int, int>> pq;

        vector<vector<int>> dist(n, vector<int>(n, -1));

        dist[0][0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){
            int x = pq.front().first;
            int y = pq.front().second;
            pq.pop();

            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int nx = x +i;
                    int ny = y + j;

                    if(nx < n && nx >= 0 && ny < n && ny >= 0 && !grid[nx][ny] && dist[nx][ny] == -1){
                        dist[nx][ny] = 1 + dist[x][y];
                        pq.push({nx, ny});
                    }
                }
            }
            
        }
        return dist[n-1][n-1];

    }
};