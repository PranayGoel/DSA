class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<string> ans;

        for(int i = 0; i< n ;i++){
            string temp;
            int div_nums = 0;

            for(int j = i; j < n; j++){
                if(nums[j]%p == 0){
                    div_nums++;
                }
                if(div_nums > k){
                    break;
                }
                temp.push_back('0' + nums[j]);
                ans.insert(temp);
            }
        }
        return ans.size();

    }
};
