class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 0);
        for(int i = 0; i<= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node== parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) {
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+= size[ulp_v];
        }
    }
};

class Solution {
public:

    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, DisjointSet &ds){
        
        int n = grid.size();
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int drow[4]= {-1, 0, 1, 0};
            int dcol[4] = {0, -1, 0, 1};
            for(int i = 0; i< 4; i++){
                int nrow = x + drow[i];
                int ncol = y + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol]){
                    if(grid[nrow][ncol] == 1){
                        int node = x*n + y;
                        int adjnode = nrow*n+ncol;
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});

                        if(ds.findUPar(node) != ds.findUPar(adjnode)){
                            ds.unionBySize(node, adjnode);
                        }
                    }
                }
            }

        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        DisjointSet ds(n*n);

        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    bfs(i, j, vis, grid, ds);
                }
            }
        }

        int ans= 0;
        bool hasZero = false;
        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    hasZero = true;
                    int size = 0;
                    unordered_set<int> uniqueParents;
                    int drow[4]= {-1, 0, 1, 0};
                    int dcol[4] = {0, -1, 0, 1};

                    for(int k = 0; k< 4; k++){
                        int nrow = i + drow[k];
                        int ncol = j + dcol[k];

                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                            if(grid[nrow][ncol] == 1){
                                int node = nrow*n + ncol;
                                int parent = ds.findUPar(node);
                                if(uniqueParents.find(parent) == uniqueParents.end()){
                                    size += ds.size[parent];
                                    uniqueParents.insert(parent);
                                }
                                
                            }
                        }
                    }
                    ans = max(ans, size+1);
                }
            }
        }

        if(!hasZero){
            for(int i = 0; i < n*n; i++){
                if(ds.findUPar(i) == i){
                    ans = max(ans, ds.size[i]);
                }
            }
        }

        
        return ans;
    
    }
};