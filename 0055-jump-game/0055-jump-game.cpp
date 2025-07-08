class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for(int i = 0; i< nums.size()-1; i++){
            if(maxIndex <=i && nums[i] == 0) return false;
            maxIndex = max(nums[i] + i, maxIndex);
            if(maxIndex >= nums.size()-1) return true;
        }

        return true;
    }
};