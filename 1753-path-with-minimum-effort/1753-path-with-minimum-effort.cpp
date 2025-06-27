class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> dist(n,vector<int>(m, INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int diff = pq.top().first;

            if(x == n-1 && y == m-1) return diff;

            pq.pop();

            int drow[4] = {-1, 0, 1, 0};
            int dcol[4] = {0, -1, 0, 1};
            
            for(int i = 0; i< 4; i++){
                int nx = x + drow[i];
                int ny = y + dcol[i];


                if(nx >= 0 && nx < n && ny >= 0 && ny < m ){
                    int newdiff = abs(heights[nx][ny] - heights[x][y]);
                    int maxdiff = max(newdiff,diff);
                    if(maxdiff < dist[nx][ny]){
                        dist[nx][ny]= maxdiff;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        return 0;


    }
};