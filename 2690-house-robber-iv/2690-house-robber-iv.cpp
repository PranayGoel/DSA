class Solution {
public:

    bool canRob(int maxHouse, vector<int>& nums, int k){
        int n = nums.size();
        int count = 0;

        int i = 0;
        while(i < n){
            if(nums[i] <= maxHouse){
                count++;
                if(count == k) return true;
                i += 2;
            }
            else{
                i++;
            }
        }

        return false;
        
    }
    int minCapability(vector<int>& nums, int k) {
        
        int min = INT_MAX;
        int max = INT_MIN;

        for(int i = 0; i< nums.size(); i++){
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }

        int low = min;
        int high = max;

        int ans = high;


        while( low <= high){

            int mid = low + (high - low)/2;

            if(canRob(mid,nums, k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }

        return ans;
    }
};