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

    int calculateNode(TreeNode* root, int num)
    {
        int ans = 0;

        if(!root)
            return 0;
        
        if(root->val >= num)
        {
            ans++;
            num = max(num, root->val);
        }

        ans += calculateNode(root->left, num);
        ans += calculateNode(root->right, num);

        return ans;
    }

    int goodNodes(TreeNode* root) {
        
        return calculateNode(root, INT_MIN);
    }
};