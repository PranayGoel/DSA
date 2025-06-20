class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board){
        int m= board.size();
        int n= board[0].size();

        vis[row][col] = 1;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        for(int i = 0; i< 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow, ncol, vis, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        // traverse all the edge row and columns and start dfs from them, any 'O' encountered will be marked as visited and in the end all the unvisited 'O's are converted to 'X'
        for(int i = 0; i < m ;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, vis, board);
            }
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(i, n-1, vis, board);
            }
        }
        for(int j = 1; j < n-1; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, vis, board);
            }
            if(!vis[m-1][j] && board[m-1][j] == 'O'){
                dfs(m-1, j, vis, board);
            }
        }

        for(int i = 0; i< m ;i++){
            for(int j = 0; j< n; j++){
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }



    }
};