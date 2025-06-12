class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i> j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int profit = INT_MIN;
        for(int k = i; k <= j; k++){
            int coins = nums[i-1]*nums[k]*nums[j+1] +f(i, k-1, nums, dp) + f(k+1, j, nums, dp); 
            if(coins > profit) profit = coins;
        }

        return dp[i][j] = profit;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        //return f(1, n, nums, dp);
        
        for(int i = n; i >=1; i--){
            for(int j = 1; j <= n; j++){
                if(i > j) continue;
                int profit = INT_MIN;
                for(int k = i; k<= j; k++){
                    int coins = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    if(coins > profit) profit = coins;
                }
                dp[i][j] = profit;
            }
        }

        return dp[1][n];
    }
};