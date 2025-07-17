class Solution {
public:
    
    bool isPossible(int mid, vector<int>& stones){

        int n = stones.size();

        vector<int> visited(n, 0);

        int stonePointer = 0;

        while( stonePointer +1 < n){
            
            int curStone = stonePointer; 

            while( stonePointer + 1 < n && stones[stonePointer + 1] - stones[curStone] <= mid ){
                stonePointer++;
            }
            if(stonePointer == curStone) return false;

            visited[stonePointer] = 1;
        }

        vector<int> unvisited;

        for(int i = 0; i < n-1 ; i++){
            if(visited[i] == 0)
                unvisited.push_back(i);
        }
        unvisited.push_back(n-1);

        stonePointer = unvisited.size() -1;


        while(stonePointer-1 >= 0){

            int curStone = stonePointer;

            while(stonePointer - 1 >= 0 && stones[unvisited[curStone]] - stones[unvisited[stonePointer-1]] <= mid ){
                stonePointer--;
            }

            if(stonePointer == curStone) return false;

        }

        return true;
    }
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        vector<int> visited(n, 0);

        int low = 0;
        int high = stones[n-1] - stones[0];

        int ans = high;
        while(low <= high){
            int mid = low + ( high - low)/2;

            if(isPossible(mid, stones)){
                ans = mid;
                high = mid-1;
            }
            else 
                low = mid+1;
        }

        return ans;
    }   

};