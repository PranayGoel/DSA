class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, maxLen = INT_MIN;
        int n = nums.size();
        int zeroCount = 0;

        while(r < n){

            if(nums[r] == 0) zeroCount++;

            while(zeroCount > k){
                if(nums[l] == 0) zeroCount--;
                l++;
            }

            maxLen = max(r-l+1, maxLen);
            r++;
        }

        return maxLen;
    }
};