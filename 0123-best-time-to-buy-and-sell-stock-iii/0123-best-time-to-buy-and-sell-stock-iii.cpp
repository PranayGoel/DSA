class Solution {
public:
    int solve(int ind, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){


        if(k <= 0 || ind == prices.size()) return 0;

        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];
        if(buy == 1){
            return dp[ind][buy][k] = max(-prices[ind] + solve(ind+1, 0, k, prices, dp), solve(ind+1, 1, k, prices, dp));
        }
        else{
            return dp[ind][buy][k] = max(prices[ind]+ solve(ind+1, 1, k-1, prices, dp), solve(ind+1, 0, k, prices, dp));
        }


    }
    int maxProfit(vector<int>& prices) {
        int n=  prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));

        return solve(0, 1, 2, prices, dp);
    }
};