class Solution {
public:
    bool isPossible(int days, vector<int>& bloomDay, int m, int k){

        int n = bloomDay.size();
        int flowerCount = 0;
        int boq = 0;

        for(int i = 0; i< n; i++){
            if(bloomDay[i] <= days){
                flowerCount++;
                if(flowerCount == k){
                    boq++;
                    flowerCount = 0;
                }
            }
            else{
                flowerCount = 0;
            }
        }
        return boq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size() ) return -1;
        
        int low = INT_MAX;
        int high = INT_MIN;

        for(auto i : bloomDay){
            low = min(low, i);
            high = max(high, i);
        }

        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(isPossible(mid, bloomDay, m, k)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};