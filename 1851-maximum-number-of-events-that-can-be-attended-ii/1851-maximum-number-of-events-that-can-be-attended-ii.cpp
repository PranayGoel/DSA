class Solution {
public:
    int f(int ind, int k, vector<vector<int>>& events, vector<vector<int>>& dp, vector<int>& next){
        int n = events.size();
        if(ind == n || k == 0) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];

        int pick = events[ind][2] + f(next[ind], k-1, events, dp, next);
        int not_pick = f(ind+1, k, events, dp, next);
        
        return dp[ind][k] = max(pick, not_pick);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {

        int n = events.size();
        sort(events.begin(), events.end());

        vector<vector<int>> dp(n + 1, vector<int>(k+1, -1));
        vector<int> next(n, n);

        for(int i = 0; i< n ;i++){
            for(int j = i+1; j < n; j++){
                if(events[j][0] > events[i][1]){
                    next[i] = j;
                    break;
                }
            }
        }
        return f(0, k, events, dp, next);

    }
};