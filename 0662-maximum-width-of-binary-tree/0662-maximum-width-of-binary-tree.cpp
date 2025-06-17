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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});


        while(!q.empty()){
            int size = q.size();
            long long minIndex = q.front().second;
            long long first, last;

            for(int i = 0; i < size; ++i){
                long long curInd = q.front().second - minIndex;
                TreeNode* front = q.front().first;

                q.pop();

                if(i == 0){
                    first = curInd;
                }
                if(i == size-1) last = curInd;

                if(front->left) q.push({front->left, 2*curInd});
                if(front->right) q.push({front->right, 2*curInd + 1});


            }
            maxWidth = max(maxWidth, last - first + 1);
        }

        return maxWidth;
    }
};