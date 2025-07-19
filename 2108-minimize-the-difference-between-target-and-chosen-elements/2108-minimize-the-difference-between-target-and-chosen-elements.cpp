class Solution {
public:

    int m, n;
    int dp[71][5000];

    int solve(int row, int sum, vector<vector<int>>& mat, int target){
        
        
        if(row >= m){
            return abs(sum - target);
        }
        if(dp[row][sum] != -1) return dp[row][sum];

        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            ans = min(ans, solve(row+1, sum + mat[row][j], mat, target));
            if(ans == 0) break;
        }

        return dp[row][sum] = ans;


    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        m = mat.size();
        n = mat[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, mat, target);

    }
};