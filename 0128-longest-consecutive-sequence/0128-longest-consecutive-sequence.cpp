class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n== 0) return 0;
        if(n==1) return 1;
        unordered_set<int> st;

        for(auto it: nums){
            st.insert(it);
        }
        int maxLen = INT_MIN;
        for(auto it: st){
            if(st.count(it-1)  == 0){
                int len = 1;
                int num = it;
                while(st.count(num+1)  >0 ) {
                    len++;
                    num++;
                }
                maxLen= max(maxLen, len);

            }
        }
        return maxLen;

    }
};