/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, vector<int>>> nodes;

        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;

        if(root== NULL) return ans;
        q.push(make_pair(root, make_pair(0, 0)));

        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode* front = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(front->val);

            if(front->left)
                q.push(make_pair(front->left, make_pair(hd-1, lvl+1)));

            if(front->right){
                q.push(make_pair(front->right, make_pair(hd+1, lvl+1)));
            }
        }

        for(auto i : nodes){
            vector<int> temp;
            for(auto j : i.second){
                vector<int>& vec= j.second;
                sort(vec.begin(), vec.end());
                for(auto k : vec){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;



    }
};