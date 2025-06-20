class Solution {
public:
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col, int prow, int pcol){
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = 1;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        for(int i = 0; i< 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == grid[row][col]){

                if(!vis[nrow][ncol]){ // if the node is not visited, then run dfs on it
                    if(dfs(grid, vis, nrow, ncol, row, col))
                        return true;
                }  
                // if it is visited, then check if its the same as the parent node, if not return true as you have travelled back to the starting node
                else if(prow != nrow && pcol != ncol)
                    return true;
            }
        }

        return false;
    }


    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j]){
                    if(dfs(grid, vis, i, j, -1, -1))
                        return true;
                }
            }
        }
        return false;

    }
};