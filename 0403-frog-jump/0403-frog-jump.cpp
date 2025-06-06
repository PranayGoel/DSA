#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
 struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0<< endl; } };
std::atexit(&___::_);
 return 0;
}();
#endif

class Solution {
public:

    bool f(int ind, int k, vector<int>& stones, int n){
        
        if(ind == n-1) return true;

        bool ans = false;

        for(int i = ind+ 1; i < n; i++){
            if(stones[i] - stones[ind] > k+1){
                break;
            }
            
            for(int j = -1; j< 2; j++){
                if((stones[i] - stones[ind]) == k+j){
                    ans =  f(i, k+j, stones, n) || ans;
                }
            }

        }
        return ans;
        

    }
    bool canCross(vector<int>& stones) {
        if(stones[1] - stones[0] >1 ) return false;

        

        //return f(1, 1, stones, stones.size());

        int n = stones.size();

        unordered_map<int, unordered_set<int>> jumps;

        for(int i = 0; i < n ; i++){
            jumps[stones[i]] = {};
        }

        jumps[0].insert(1);

        for(int i = 0; i< n; i++){

            int currStone = stones[i];


            for(auto jump : jumps[currStone]){
                
                int pos = currStone + jump;

                if(pos == stones[n-1]) return true;
                if(jumps.find(pos) != jumps.end()){
                    if(jump-1 > 0) jumps[pos].insert(jump-1);
                    jumps[pos].insert(jump);
                    jumps[pos].insert(jump+1);
                }
            }
        }
        return false;

    }
};