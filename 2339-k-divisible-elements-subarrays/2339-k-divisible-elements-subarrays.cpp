class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> ans;

        for(int i = 0; i< n ;i++){
            vector<int> temp;
            int div_nums = 0;

            for(int j = i; j < n; j++){
                temp.push_back(nums[j]);
                if(nums[j]%p == 0){
                    div_nums++;
                }
                if(div_nums > k){
                    break;
                }
                ans.insert(temp);
            }
        }
        return ans.size();

    }
};