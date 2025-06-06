class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<int> front(2, 0), cur(2,0);


        for(int ind = n-1; ind >= 0; ind--){
            cur[1] = max( -prices[ind] + front[0], front[1]);
            
            
            cur[0] = max( prices[ind] + front[1] -fee, front[0]);

            
            front = cur;
        }

        return front[1];
    }
};