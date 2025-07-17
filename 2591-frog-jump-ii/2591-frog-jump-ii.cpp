class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=  stones.size();

        if(n == 2) return stones[n-1] - stones[0];

        int maxJump = INT_MIN;
        for(int i = 0 ; i< n-2 ;i++){
            maxJump = max(maxJump, stones[i+2] - stones[i]);
        }

        return maxJump;
    }
};