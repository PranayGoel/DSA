class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for( int k = i; k<= j; k++){
            int cost = cuts[j+1] - cuts[i-1] + f(i, k-1, cuts, dp) + f(k+1, j, cuts,dp);
            if(cost < mini) mini = cost; 
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        vector<vector<int>>dp(c+2, vector<int>(c+2, 0));
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        //return f(1, c, cuts, dp);

        for(int i = c; i >= 1; i--){
            for(int j = 1; j <=c; j++){
                if(i > j) continue;
                int mini = INT_MAX;
                for(int k = i; k <= j; k++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    if(cost < mini) mini = cost;
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};