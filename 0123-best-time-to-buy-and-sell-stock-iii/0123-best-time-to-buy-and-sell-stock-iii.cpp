class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int cap, vector<vector<vector<int>>>& dp){
        if(cap == 0) return 0;
        if(ind == prices.size()) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if(buy == 1){
            return dp[ind][buy][cap] =  max( (-prices[ind] + f(ind+1, 0, prices, cap, dp)), f(ind+1, 1, prices, cap, dp));
        }
        else{
            return dp[ind][buy][cap] =  max( (prices[ind] + f(ind+1, 1, prices, cap-1, dp)), f(ind+1,0, prices, cap, dp));
        }
    }
    int maxProfit(vector<int>& prices) {

        //vector<vector<vector<int>>> dp (prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        
        //return f(0, 1, prices, 2,dp);

        /*
        int n = prices.size();
        vector<vector<vector<long long>>> dp (prices.size()+1, vector<vector<long long>>(2, vector<long long>(3, 0)));

        for(int ind = n-1; ind >=0; ind-- ){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap<= 2; cap++){
                    if(buy == 1){
                        dp[ind][buy][cap] = max( (-prices[ind] + dp[ind+1][0][cap]), dp[ind+1][1][cap]);
                    }
                    else 
                        dp[ind][buy][cap] = max( (prices[ind] + dp[ind+1][1][cap-1]), dp[ind+1][0][cap]);

                }
            }
        }

        return dp[0][1][2];
        */

        
        int n = prices.size();
        //vector<vector<vector<long long>>> dp (prices.size()+1, vector<vector<long long>>(2, vector<long long>(3, 0)));

        vector<vector<int>> ahead(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));


        for(int ind = n-1; ind >=0; ind-- ){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap<= 2; cap++){
                    if(buy == 1){
                        cur[buy][cap] = max( (-prices[ind] + ahead[0][cap]), ahead[1][cap]);
                    }
                    else 
                        cur[buy][cap] = max( (prices[ind] + ahead[1][cap-1]), ahead[0][cap]);

                }
            }
            ahead = cur;
        }

        return ahead[1][2];
    }
};