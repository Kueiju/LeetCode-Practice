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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p == nullptr && q == nullptr)
            return true;

        if(p == nullptr || q == nullptr)
            return false;    

        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while(!st.empty())
        {
            auto [node1, node2] = st.top();
            st.pop();

            if(node1 == nullptr && node2 == nullptr)
                continue;

            if(node1 == nullptr || node2 == nullptr)
                return false;

            if(node1->val != node2->val)
                return false;
            
            st.push({node1->left, node2->left});
            st.push({node1->right, node2->right});
        }

        return true;
    }
};