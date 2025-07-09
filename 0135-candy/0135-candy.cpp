class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for(int i= 1; i< ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        for(int i = n-2; i >= 0; i--){
            while(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]){
                candies[i]++;
            }
        }

        int sum = 0;

        for(auto i: candies){
            sum += i;
        }
        return sum;
    }
};