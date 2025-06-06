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
        //vector<vector<int>> dp(prices.size(), vector<int>(2*k, -1));

        //return f(0, 0, prices, prices.size(),  k, dp);

        //vector<vector<int>> dp(prices.size()+1, vector<int>(2*k+1, 0));

        vector<int> ahead(2*k+1,0), cur(2*k+1, 0);

        int n = prices.size();

        for(int ind = n-1 ; ind >= 0; ind--){
            for(int tran = 2*k-1; tran >= 0; tran--){
                if(tran%2 == 0){
                    cur[tran]= max(-prices[ind] +ahead[tran+1], ahead[tran]);
                }
                else{
                    cur[tran] = max(prices[ind] + ahead[tran+1], ahead[tran]);
                }
            }
            ahead = cur;
        }

        return ahead[0];
    }
};