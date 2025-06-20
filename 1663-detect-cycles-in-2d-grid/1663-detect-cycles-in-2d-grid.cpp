class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j]){
                    queue<tuple<int, int, int, int>> q;
                    q.push({i, j, -1, -1});
                    vis[i][j] = 1;

                    while(!q.empty()){
                        auto [row, col, prow, pcol] = q.front();
                        q.pop();

                        int delrow[4] = {-1, 0, 1, 0};
                        int delcol[4] = {0, -1, 0, 1};
                        
                        for(int k = 0; k< 4; k++){
                            int nrow = row + delrow[k];
                            int ncol = col + delcol[k];

                            if(nrow >= 0 && nrow <m && ncol >= 0 && ncol < n && grid[nrow][ncol] == grid[row][col]){
                                if(!vis[nrow][ncol]){
                                    vis[nrow][ncol] = 1;
                                    q.push({nrow, ncol, row, col});
                                }
                                else if(nrow != prow || ncol != pcol){
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
        
        



    }
};