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

    bool checkBST(TreeNode* node, int min, int max)
    {
        if(node == nullptr)
            return true;
        
        if(node->val > min && node->val < max)
        {
            bool left = checkBST(node->left, min, node->val);
            bool right = checkBST(node->right, node->val, max);
            
            return left && right;
        }
        
        return false;
    }

    bool isValidBST(TreeNode* root) {
        
        return checkBST(root, INT_MIN, INT_MAX);
    }
};