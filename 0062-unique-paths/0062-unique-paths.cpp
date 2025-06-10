
class Solution {
public:
    /*

    int solve(int row, int col, vector<vector<int>>& dp){

        if(row == 0 && col == 0) return 1;
        if((row == 0 && col ==1) || (row == 1 && col == 0)) return 1;

        if(dp[row][col] != 0) return dp[row][col];

        int right = 0, down = 0;

        if(col > 0) right = solve(row, col - 1, dp) ;
        if(row > 0) down = solve(row-1, col,dp)  ;

        return dp[row][col] = down + right ;

    }
    */

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int> (n, 1));
        
        //return solve(m-1, n-1, dp);

        //bottom up

    
        for(int i = 1; i< m; i++){
            for(int j = 1; j < n; j++){
                
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];

    
    }
};