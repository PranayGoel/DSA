class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int,int> mp;

        for(int i = 0; i< n; i++){
            mp[hand[i]]++;
        }

        for(auto it: mp){
            int card = it.first;
            int count = it.second;

            if(count == 0) continue;

            for(int i = 1; i < groupSize; i++){
                int next = card+i;
                if(mp[next] < count) return false;
                mp[next] -=count;
            }
        }

        return true;

    }
};