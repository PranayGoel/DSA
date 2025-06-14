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

    int isPossible(vector<int> arr, int day, int k, int m){

        int count = 0, b = 0;

        for(int j = 0; j< arr.size(); j++){
            if(arr[j] <= day) count++;
            else{
                b+= count/k;
                count = 0;
            }
        }
        b += count/k;
        if(b >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(n < (long long)m*k) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        if(low == high) return low;
        
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(isPossible(bloomDay, mid, k, m)) {
                ans= mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};
