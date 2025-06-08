class Solution {
public:

    

    int f(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(ind == n) return 0;
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        int len = f(ind+1, prev_ind, nums, n, dp); // not_take
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len,1+ f(ind+1, ind, nums, n, dp));
        }

        return dp[ind][prev_ind+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {    

        //vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
        //return f(0, -1, nums, nums.size(), dp);

        /* bottom up
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        // prev_ind is 1 shifted / 1 indexed, because it goes from -1 to n-1, -1 index is not possible so store -1 to n-1 in 0 to n
        //simply add +1 to prev_ind in dp[ind][prev_ind]

        for(int ind = n-1; ind >=0; ind--){
            for(int prev_ind = ind-1 ; prev_ind >= -1; prev_ind--){
                int len = dp[ind+1][prev_ind+1];
                if(prev_ind == -1 || nums[ind] > nums[prev_ind])
                    len = max(len, 1 + dp[ind+1][ind+1]);

                dp[ind][prev_ind+1] = len;
            }
        }

        return dp[0][-1+1];
        */

        //bottom up with space optimization
        // tc - o(n^2), sc - o(n)
        /*
        int n = nums.size();
        vector<int> ahead(n+1, 0), cur(n+1, 0);

        for(int ind = n-1; ind >=0; ind--){
            for(int prev_ind = ind-1 ; prev_ind >= -1; prev_ind--){
                int len = ahead[prev_ind+1];
                if(prev_ind == -1 || nums[ind] > nums[prev_ind])
                    len = max(len, 1 + ahead[ind+1]);

                cur[prev_ind+1] = len;
            }
            ahead= cur;
        }

        return ahead[-1+1];
        */

        int n=  nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;

        for(int i = 1; i< n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }   
        return len;
    }
};