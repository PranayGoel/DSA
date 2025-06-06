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
        vector<vector<vector<int>>> dp (prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, prices, 2,dp);
    }
};