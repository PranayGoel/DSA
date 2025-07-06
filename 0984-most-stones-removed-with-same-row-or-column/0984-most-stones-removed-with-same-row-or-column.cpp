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
    int removeStones(vector<vector<int>>& stones) {
        DisjointSet ds(stones.size());
        for(int i = 0; i < stones.size(); i++){
            for(int j = 0; j < stones.size(); j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    if(ds.findUPar(i) != ds.findUPar(j))
                        ds.unionBySize(i, j);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i< stones.size(); i++){
            if(ds.parent[i] == i){
                ans += ds.size[i] - 1;
            }
        }

        return ans;
    }
};