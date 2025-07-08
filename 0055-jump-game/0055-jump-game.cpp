class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for(int i = 0; i< nums.size()-1; i++){
            if(nums[i] == 0){
                if(maxIndex > i) continue;
                else break;
            }
            maxIndex = max(nums[i] + i, maxIndex);
        }

        return maxIndex>=nums.size()-1 ? true : false;
    }
};