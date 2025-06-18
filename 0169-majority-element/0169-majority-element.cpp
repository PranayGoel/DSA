class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;

        for(auto num: nums){
            if(cnt == 0){
                cnt = 1;
                el = num;
            }
            else if(num == el) cnt++;
            else cnt--;
        }

        int cnt1 = 0;
        for(auto num: nums) if(num == el) cnt1++;

        if(cnt1 > nums.size()/2) return el;
        else return -1;
    }
};