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

        if(root == nullptr)
            return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});

        int goodnode = 0;
        //int max1 = INT_MIN;

        while(!st.empty())
        {
            auto [node, val] = st.top();
            st.pop();

            int max1 = max(node->val, val);

            if(val >= max1)
            {
                goodnode++;
            }

            if(node->left != nullptr)
            {
                st.push({node->left, max1});
            }

            if(node->right != nullptr)
            {
                st.push({node->right, max1});
            }
        }
        
        return goodnode;
    }
};