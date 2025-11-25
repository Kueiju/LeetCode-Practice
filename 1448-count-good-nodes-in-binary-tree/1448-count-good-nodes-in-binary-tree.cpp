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

        stack<pair<TreeNode*, int>> st;
        st.push(pair(root, INT_MIN));
        
        int ans = 0;
        
        while(!st.empty())
        {
            auto [node, val] = st.top();
            st.pop();

            int maxval = val;
            if(node->val >= maxval)
            {
                ans++;
                maxval = node->val;
            }

            if(node->left)
            {
                st.push(pair(node->left, maxval));
            }

            if(node->right)
            {
                st.push(pair(node->right, maxval));
            }
        }

        return ans;
    }
};