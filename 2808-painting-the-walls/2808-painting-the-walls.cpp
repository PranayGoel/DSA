class Solution {
public:

    int f(int ind, int left, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp){
        if(left <= 0){// if there are no walls left, then cost from that point onwards will be 0
            return 0; 
        }
        if(ind == 0) {
            if(left <= 1+ time[0]) return cost[0];
            else return 1e9;
        }

        if(dp[ind][left] != -1) return dp[ind][left];

        int notTakenCost = f(ind-1, left, cost,time, dp);
        int takenCost = cost[ind] + f(ind-1, left - 1 - time[ind], cost, time, dp);

        return dp[ind][left] = min(notTakenCost, takenCost);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size(), vector<int>(cost.size()+1, -1));

        return f(cost.size()-1, cost.size(), cost, time, dp);
    }

};