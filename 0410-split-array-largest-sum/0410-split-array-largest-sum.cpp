class Solution {
public:
    
    int solve(int ind, int k, vector<int>& nums, vector<vector<int>>& dp){
        if(k == 1){
            int sum  =0;
            for(int i = ind; i< nums.size(); i++){
                sum += nums[i];
            }
            return sum;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int leftSum = 0;
        int ans = INT_MAX;
        for(int i = ind; i <= nums.size() -k; i++){
            leftSum += nums[i];
            int rightSum = solve(i+1, k-1, nums, dp);
            int temp = max(leftSum, rightSum);
            ans = min(ans, temp);
        }
        return dp[ind][k] = ans;
    }
    
    
    int splitArray(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(k+1, -1));
        return solve(0, k, nums, dp);    
    
    }
};