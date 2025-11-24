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
    int dfs(TreeNode* root, int max_so_far)
    {
        if(root == nullptr)
            return 0;
        
        int ans = (root->val >= max_so_far) ? 1 : 0;
        max_so_far = max(max_so_far, root->val);

        ans += dfs(root->left, max_so_far);
        ans += dfs(root->right, max_so_far);

        return ans;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};