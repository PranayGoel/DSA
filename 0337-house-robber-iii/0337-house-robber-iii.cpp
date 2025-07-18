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

    pair<int, int> solve(TreeNode* root){
        if(root == NULL) return make_pair(0, 0);

        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);

        pair<int,int> ans;

        ans.first = root->val + leftAns.second + rightAns.second;  // if picking current value, sum with not_pick of left and right subtree
        ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

        return ans;
        
    }

    int rob(TreeNode* root) {
        // <pick, not_pick>
        pair<int, int> ans;

        ans = solve(root);

        return max(ans.first, ans.second);

    }
};