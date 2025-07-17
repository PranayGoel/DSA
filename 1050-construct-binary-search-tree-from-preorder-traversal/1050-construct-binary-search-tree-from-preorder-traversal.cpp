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

    void insert(TreeNode* root, int val){

        if(val < root->val){
            if(!root->left){
                root->left = new TreeNode(val);
                return;
            }
            insert(root->left, val);
        }
        else{
            if(!root->right){
                root->right= new TreeNode(val);
                return;
            }
            insert(root->right, val);
        }

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();

        TreeNode* root = new TreeNode(preorder[0]);

        for(int i = 1; i < n ;i++){
            insert(root, preorder[i]);
        }

        return root;
        


    }
};