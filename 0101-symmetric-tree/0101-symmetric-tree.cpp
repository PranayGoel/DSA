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
    bool solve(TreeNode* leftNode, TreeNode *rightNode){
        if(!leftNode && !rightNode) return true;

        if(leftNode && rightNode && leftNode->val == rightNode->val){
            bool leftAns = solve(leftNode->right, rightNode->left);
            bool rightAns = solve(leftNode->left, rightNode->right);
            return leftAns && rightAns;
        }else return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return solve(root->left, root->right);
    }
};