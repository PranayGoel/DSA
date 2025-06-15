class Solution {
public:
    bool sumLessThanT(vector<int>& nums, int d, int t){
        int sum = 0;
        for(auto num: nums){
            sum += (num + d - 1)/d;
        }
        if(sum <= t) return true;
        else return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(sumLessThanT(nums, mid, threshold)){
                ans = mid;
                high = mid-1;
            }
            else 
                low = mid+1;
        }

        return ans;
    }
};