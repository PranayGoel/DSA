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
    TreeNode* find_min(TreeNode* root){
        
        if(!root->left) return root;
        
        return find_min(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL) return NULL;

        if(root->val == key){
            
            // no child
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            // 1 child

            else if(root->left && !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left && root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // 2 child

            else{
                TreeNode* minRight = find_min(root->right);
                root->val= minRight->val;
                root->right = deleteNode(root->right, minRight->val);
                return root;
            }


        }
        else{
            if(key < root->val){
                root->left = deleteNode(root->left, key);
            }
            else{
                root->right = deleteNode(root->right, key);
            }
        }

        return root;
    }
};