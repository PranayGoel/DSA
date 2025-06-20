class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int m= grid.size();
        int n= grid[0].size();

        vis[row][col] = 1;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        for(int i = 0; i< 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i < m ;i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0, vis, grid);
            }
            if(!vis[i][n-1] && grid[i][n-1] == 1){
                dfs(i, n-1, vis, grid);
            }
        }
        for(int j = 1; j < n-1; j++){
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0, j, vis, grid);
            }
            if(!vis[m-1][j] && grid[m-1][j] == 1){
                dfs(m-1, j, vis, grid);
            }
        }
        int count = 0;
        for(int i = 0; i< m ;i++){
            for(int j = 0; j< n; j++){
                if(!vis[i][j] && grid[i][j] == 1)
                    count++;
            }
        }

        return count;


    }
};