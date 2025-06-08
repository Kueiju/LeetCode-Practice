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
    bool dfs(TreeNode* node, long maxval, long minval)
    {
        if(node == nullptr)
            return true;

        if(node->val > minval && node->val < maxval)
        {
            bool left = dfs(node->left, node->val, minval);
            bool right = dfs(node->right, maxval, node->val);
            return left && right;
        }
        else
            return false;
    }

    bool isValidBST(TreeNode* root) {

        return dfs(root, LONG_MAX, LONG_MIN);
        
    }
};