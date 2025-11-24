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
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root == nullptr)
            return false;
        
        stack<pair<TreeNode*, int>> st;
        st.push(pair(root, targetSum - root->val));

        while(!st.empty())
        {
            auto [node, val] = st.top();
            st.pop();

            if((node->left == nullptr) && 
               (node->right == nullptr) && 
               (val == 0))
                return true;

            //targetSum -= val;

            if(node->left)
            {
                st.push(pair(node->left, val - node->left->val));
            } 

            if(node->right)
            {
                st.push(pair(node->right, val - node->right->val));
            }

            //cout << targetSum << endl;
        }

        return false;
    }
};