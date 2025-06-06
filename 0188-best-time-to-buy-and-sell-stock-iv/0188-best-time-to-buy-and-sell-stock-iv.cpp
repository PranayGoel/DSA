class Solution {
public:
    int f(int ind, int tran, vector<int>& prices, int n, int k, vector<vector<int>>& dp){
        if(ind == n || tran == 2*k) return 0;

        if(dp[ind][tran] != -1) return dp[ind][tran];

        if(tran%2 == 0) { //buy
            return dp[ind][tran] =  max( -prices[ind] + f(ind+1, tran+1, prices, n, k,dp), f(ind+1, tran, prices, n, k, dp));
        }
        else{
            return dp[ind][tran] = max( prices[ind] + f(ind+1, tran+1, prices, n, k, dp), f(ind+1,tran ,prices, n, k, dp));
        }

    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k, -1));

        return f(0, 0, prices, prices.size(),  k, dp);

    }
};