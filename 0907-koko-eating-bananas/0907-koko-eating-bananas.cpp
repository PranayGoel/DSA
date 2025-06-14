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
        
        while(low < high){
            int mid = low + (high-low)/2;
            int count = 0;
            for(auto pile: piles){
                count += (pile + mid -1) / mid;
            }

            if(count <= h) {
                high = mid;
            }
            else 
                low = mid+1;

        }
        return low;

    }
};