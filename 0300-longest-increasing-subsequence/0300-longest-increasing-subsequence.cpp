class Solution {
public:
    int solve(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){

        if(ind == nums.size()) return 0;

        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int not_pick = solve(ind+1, prev, nums, dp);
        int pick = 0;
        if( prev == -1 || nums[ind] > nums[prev]){
            pick = 1 + solve(ind+1, ind, nums, dp);
        }

        return dp[ind][prev+1] = max(pick, not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+2, -1));
        return solve(0,-1, nums, dp);
    }
};