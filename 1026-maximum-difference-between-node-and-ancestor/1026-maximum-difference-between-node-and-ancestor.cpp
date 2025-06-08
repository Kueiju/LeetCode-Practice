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
    int dfs(TreeNode* node, int max, int min)
    {   
        if(node == nullptr)
            return max - min;
        
        max = std::max(max, node->val);
        min = std::min(min, node->val);
        
        return std::max(dfs(node->left, max, min), dfs(node->right, max, min));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};

//time complexity: O(n), since we have to visit each node
//space complexity: O(n), worst case if it is skewed tree, O(logn) if it is a balanced tree