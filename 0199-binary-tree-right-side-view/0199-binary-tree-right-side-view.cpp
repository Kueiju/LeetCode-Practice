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
    vector<int> rightSideView(TreeNode* root) {

        if(root == nullptr)
            return vector<int>();

        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;

        while(!q.empty())
        {
            int nodelevel = q.size();

            //vector<int> temp;

            for(int i = 0; i < nodelevel; i++)
            {
                TreeNode* level = q.front();
                q.pop();

                if(i == nodelevel - 1)
                ans.emplace_back(level->val);

                if(level->left)
                {
                    q.push(level->left);
                }

                if(level->right)
                {
                    q.push(level->right);
                }
            }

            //ans.emplace_back(temp.back());
        }
        
        return ans;
    }
};