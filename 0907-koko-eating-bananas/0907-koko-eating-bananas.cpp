/*
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int k = 1;

        while(true){

            int count = 0;
            for(auto pile: piles)
                count += ceil((double)pile /k);

            if(count <= h) return k;
            else k++;

        }
    }
};
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;
            long long  count = 0;
            for(auto pile: piles){
                count += (pile + mid -1) / mid; //ceil(pile/mid)
            }

            if(count <= h) {
                ans = mid;
                high = mid-1;
            }
            else 
                low = mid+1;

        }
        return ans;
        // tc - O(piles.size() * log(max_element))
    }
};