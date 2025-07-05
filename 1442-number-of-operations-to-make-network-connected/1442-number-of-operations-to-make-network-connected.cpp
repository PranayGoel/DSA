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

    void unionBySize(int u, int v, int &ans){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) {
            ans++;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int ans = 0;
        for(int i = 0; i< connections.size(); i++){
            ds.unionBySize(connections[i][0], connections[i][1], ans);   
        }

        int components = 0;
        for(int i = 0; i< n ; i++){
            if(ds.parent[i] == i) components++;
        }

        int reqEdges = components - 1;
        return (ans >= reqEdges) ? reqEdges: -1;


    }
};