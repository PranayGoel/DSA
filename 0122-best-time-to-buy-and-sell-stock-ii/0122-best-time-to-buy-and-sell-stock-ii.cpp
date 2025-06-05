class Solution {
public:

    int f(int ind, int buy, vector<int>& prices, vector<vector<int>>&dp){
        if(ind == prices.size())
            return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy == 1){
            return dp[ind][buy] = max( (-prices[ind] + f(ind+1, 0, prices, dp)), f(ind+1, 1, prices, dp));
        }
        else{
            return dp[ind][buy] = max( (prices[ind] + f(ind+1, 1, prices, dp)), f(ind+1, 0, prices, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        //vector<vector<int>> dp(prices.size(), vector<int>(2, -1));

        //return f(0, 1, prices, dp);

        /*
        vector<vector<long>> dp(prices.size()+1, vector<long>(2, 0));

        for(int ind = prices.size()-1; ind >=  0; ind--){
            for(int buy = 0; buy <=1; buy++){

                if(buy == 0){
                    dp[ind][buy] = max( (+prices[ind] + dp[ind+1][1]), dp[ind+1][0]);
                }else
                    dp[ind][buy] = max( (-prices[ind] + dp[ind+1][0]), dp[ind+1][1]);
            }

        }
        return dp[0][1];
        */

        vector<long> ahead(2,0), cur(2,0);
        
        for(int ind = prices.size()-1; ind>=0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                long profit = 0;
                if(buy){
                    profit = max((-prices[ind] + ahead[0]), ahead[1]);

                }
                else
                    profit = max((prices[ind] + ahead[1]), ahead[0]);

                cur[buy]  =profit;
            }
            ahead = cur;
        }
        return ahead[1];
    }
};