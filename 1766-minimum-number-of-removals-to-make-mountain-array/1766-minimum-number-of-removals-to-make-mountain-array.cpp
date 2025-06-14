class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp_front(n, 1);
        
        for(int i = 1; i< n; i++){
            for(int prev= 0; prev < i; prev++){
                if(nums[prev] < nums[i] && dp_front[prev] + 1 > dp_front[i]){
                    dp_front[i]  = dp_front[prev] + 1;
                }
            }
    
        
        }
        
        vector<int>dp_back(n, 1);
        
        for(int i = n-1; i >= 0; i--){
            for(int prev = n-1; prev > i; prev--){
                if(nums[prev] < nums[i] && dp_back[prev] + 1 > dp_back[i]){
                    dp_back[i] = dp_back[prev] + 1;
                }
            }
        }
            
        int maxi = 0;
        
        for(int i = 0; i< n; i++){
            if(dp_front[i] > 1 && dp_back[i] > 1) maxi = max(maxi, dp_front[i] + dp_back[i] -1);
        }
        return n - maxi;
    }
};