class Solution {
public:
    int daysTaken(int maxWeight, vector<int>& weights){
        int day = 1;
        int load = 0;

        for(auto weight : weights){
            if(load + weight > maxWeight){
                day++;
                load = weight;
            }
            else load+= weight;
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int high = sum;
        int ans = high;
        while( low <= high){
            int mid = low + (high - low)/2;
            if(daysTaken(mid, weights) <= days){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;

    }
};