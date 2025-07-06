class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u), pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);

        unordered_map<int, vector<int>> rowMap, colMap;

        // Group stone indices by row and column
        for (int i = 0; i < n; i++) {
            rowMap[stones[i][0]].push_back(i);
            colMap[stones[i][1]].push_back(i);
        }

        // Union stones in the same row
        for (auto& [_, indices] : rowMap) {
            for (int i = 1; i < indices.size(); i++) {
                ds.unionBySize(indices[i], indices[0]);
            }
        }

        // Union stones in the same column
        for (auto& [_, indices] : colMap) {
            for (int i = 1; i < indices.size(); i++) {
                ds.unionBySize(indices[i], indices[0]);
            }
        }

        // Count connected components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) components++;
        }

        return n - components;
    }
};
