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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* node, int max_so_far)
    {
        if(node == nullptr)
            return 0;

        int ans = (node->val >= max_so_far) ? 1 : 0;
        max_so_far = max(max_so_far, node->val);

        ans += dfs(node->left, max_so_far);
        ans += dfs(node->right, max_so_far);

        return ans;
    }


};