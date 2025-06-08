class Solution {
public:

    

    int maxProduct(vector<int>& nums) {

        int prefix = 1;
        int suffix = 1;

        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            prefix *= nums[i];
            ans = max(prefix, ans);
            if(prefix == 0) prefix = 1;

        }

        for(int i = nums.size()-1; i >=0 ; i--){
            suffix *= nums[i];
            ans = max(suffix, ans);
            if(suffix == 0) suffix = 1;

        }

        return ans;

    }
};

