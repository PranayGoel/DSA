class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n= mat[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dis(m, vector<int>(n, 0));

        queue<pair<int, int>>q;

        for(int i = 0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    dis[i][j] = 0;
                    vis[i][j] = 1;

                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[4] = {-1, 0, 1, 0};
            int delcol[4] = {0, -1, 0, 1};

            for(int i = 0; i< 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && !vis[nrow][ncol] && mat[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    dis[nrow][ncol] = 1 + dis[row][col];
                    q.push({nrow, ncol});
                }
            }
        }

        return dis;
    }
};