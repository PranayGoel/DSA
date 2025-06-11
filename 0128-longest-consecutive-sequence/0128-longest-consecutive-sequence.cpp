class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : st) {
            // Start only if it's the beginning of a sequence
            if (!st.count(num - 1)) {
                int currentNum = num;
                int len = 1;

                while (st.count(currentNum + 1)) {
                    currentNum++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;

    }
};