class Solution {
public:
    int f(int ind, vector<int>& arr){
        if(ind <0) return 0;
        if(ind == 0) return arr[0];

        int pick = arr[ind] + f(ind-2, arr);
        int not_pick = f(ind-1, arr);

        return max(pick, not_pick);
    }

    int rob(vector<int>& arr) {
        int n = arr.size();

        int prev1 = arr[0];
        int prev2 = 0;
        int cur;
        for(int i = 1; i< n; i++){
            if(i == 1) cur = max(arr[i], prev1);
            else{
                int pick = arr[i] + prev2;
                int not_pick = prev1;

                cur = max(pick, not_pick);
            }
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};