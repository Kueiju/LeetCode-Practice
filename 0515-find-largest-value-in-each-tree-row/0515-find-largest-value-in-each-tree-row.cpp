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
    vector<int> largestValues(TreeNode* root) {

        if(root == nullptr)
            return vector<int>();

        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;

        while(!q.empty())
        {
            int nodelevel = q.size();
            int maxval = INT_MIN;

            for(int i = 0; i < nodelevel; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                maxval = max(maxval, node->val);

                if(node->left)
                {
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }
            }

            ans.emplace_back(maxval);
        }

        return ans;   
    }
};