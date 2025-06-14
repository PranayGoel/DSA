/*
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(n < m*k) return -1;

        int min = *min_element(bloomDay.begin(), bloomDay.end());
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        
        if(min == max) return min;

        for(int i = min; i <= max; i++){
            int count = 0; int b = 0;
            for(int j = 0; j < n; j++){
                if(bloomDay[j] <= i) count++;
                else{
                    b += count /k;
                    count = 0;
                }
            }

            b+= count/k;
            if(b == m) return i;
        }
        return -1;
    }
};

*/

class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int mid){
        int bouquets = 0;
        int count = 0;

        for(auto x : bloomDay){
            if(mid >= x){
                count++;

                if(count == k){
                    bouquets++;
                    count = 0;
                }
            }

            else count = 0;
        }

        if(bouquets >= m) return true;

        return false;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = 1, hi = INT_MIN;
        int ans = -1;

        for(auto x : bloomDay) hi = max(hi, x);

        while(hi >= lo){
            int mid = lo + (hi-lo)/2;

            if(possible(bloomDay, m, k, mid)){
                ans = mid;
                hi = mid - 1;
            }

            else lo = mid + 1;
        }

        return ans;
    }
};