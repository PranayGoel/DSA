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
    bool f(TreeNode* root, long long lowest, long long highest){
        if(root == NULL) return true;

        if(root->val <= lowest || root->val >= highest) return false;

        return f(root->left, lowest, root->val) && f(root->right, root->val, highest);
    }
    bool isValidBST(TreeNode* root) {
        

        return f(root, LLONG_MIN, LLONG_MAX);
    }   
};