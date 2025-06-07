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

    bool dfs(TreeNode* root, long min, long max)
    {
        //vector<int> vec;
        if(root == nullptr)
            return true;
        
        if(root->val > min && root->val < max)
        {
            bool left = dfs(root->left, min, root->val);
            bool right = dfs(root->right, root->val, max);

            return left && right;
        }
        else
            return 0;
    }

    bool isValidBST(TreeNode* root) {
        
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};