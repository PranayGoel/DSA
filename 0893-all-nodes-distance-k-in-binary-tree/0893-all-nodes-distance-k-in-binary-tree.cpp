/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parents(unordered_map<TreeNode*, TreeNode*>& parents, TreeNode* root){

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parents[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parents[node->right] = node;
                q.push(node->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root == NULL) return ans;

        unordered_map<TreeNode*, TreeNode*> parents;
        mark_parents(parents, root);

        unordered_map<TreeNode*, bool> visited;

        int level = 0;

        queue<TreeNode*> q;
        q.push(target);

        while(!q.empty()){
            int n = q.size();
            if(level == k) break;
            level++;

            for(int i = 0; i< n; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                visited[frontNode] = true;

                if(frontNode->right && !visited[frontNode->right]){
                    q.push(frontNode->right);
                }
                if(frontNode->left && !visited[frontNode->left]){
                    q.push(frontNode->left);
                }
                if(parents[frontNode] && !visited[parents[frontNode]]){
                    q.push(parents[frontNode]);
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
    
};