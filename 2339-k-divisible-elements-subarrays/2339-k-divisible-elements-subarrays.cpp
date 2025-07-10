class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        unordered_set<string> st;

        int l = 0, r = 0, count = 0;

        while( r< n){
            if(nums[r] % p == 0) count++;
            while(count > k){
                if(nums[l] % p == 0) count--;
                l++;
            }
            string temp = "";
            for(int j = r ; j >= l; j--){
                temp.push_back('0' + nums[j]);
                st.insert(temp);
            }
            r++;
        }


        return st.size();

    }
};