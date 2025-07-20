class Solution {
public:

    int splits(int maxSum, vector<int>& nums){

        int split = 1;
        int sum = 0;
        for(int i = 0; i< nums.size(); i++){
            if(sum + nums[i] <= maxSum){
                sum += nums[i];
            }
            else{
                sum = nums[i];
                split++;
            }
        }
        return split;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int low = INT_MIN;
        int high = 0;

        for(auto i: nums){
            low = max(low, i);
            high += i;
        }

        int ans;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(splits(mid, nums) > k){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }

        return ans;
    }
};