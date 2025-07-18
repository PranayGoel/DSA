class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& dp){
        
        if(m == 0 && n == 0) return 1;

        if(dp[m][n] != -1) return dp[m][n];

        int down = 0;
        int right = 0;

        if(m > 0) down = solve(m-1, n, dp);
        if(n >  0) right = solve(m, n-1, dp);

        return dp[m][n] =  down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m-1, n-1, dp);
    }
};