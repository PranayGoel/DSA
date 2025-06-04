class Solution {
public:
    int f(int ind, int t, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0) {
            if((t % coins[ind]) == 0) return t/coins[ind];
            else return 1e9;
        }

        if(dp[ind][t] != -1 ) return dp[ind][t];

        int not_take = f(ind-1, t, coins, dp);
        int take = 1e9;
        if(coins[ind] <= t)
            take = 1 + f(ind, t-coins[ind], coins, dp);
        
        return dp[ind][t] =min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        int n = coins.size();

        /*
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));

        int ans = f(coins.size()-1, amount, coins, dp);

        return (ans >= 1e9)? -1 : ans;
        */

        //vector<vector<int>> dp(n, vector<int> (amount+1, 0));

        vector<int> prev(amount +1), cur(amount+1);
        for(int i = 0; i <= amount; i++){
            if( (i % coins[0]) == 0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }

        for(int ind = 1; ind < n; ind++){
            for(int t = 0; t <= amount; t++){
                int not_take= prev[t];
                int take = 1e9;
                if( t >= coins[ind]) 
                    take = 1 + prev[t-coins[ind]];

                prev[t] = min(take, not_take);
            }
            
        }

        int ans = prev[amount];
        return (ans >= 1e9)? -1 : ans;

    }
};