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
    int maxdia = 0;
    int diameterOfBinaryTree(TreeNode* root) {

        longpath(root);
        return maxdia;
    }

    int longpath(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int left = longpath(root->left);
        int right = longpath(root->right);
        
        
        
        cout << "left = " << left << endl;
        cout << "right = " << right << endl;
        
        maxdia = max(maxdia, left + right);
        
        return max(left, right) + 1;
    }
};