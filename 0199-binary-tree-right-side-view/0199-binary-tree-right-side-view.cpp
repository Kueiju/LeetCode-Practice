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

        vector<int> vec;

        while(!q.empty())
        {
            int currentlevel = q.size();

            vec.push_back(q.back()->val);

            for(int i = 0; i < currentlevel; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr)
                {
                    q.push(node->left);
                }

                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
        }
        
        return vec;
    }
};