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
    int deepestLeavesSum(TreeNode* root) {

        if(root == nullptr)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int sum = 0;

        while(!q.empty())
        {
            int currentlevel = q.size();
            sum = 0;
            for(int i = 0; i < currentlevel; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                sum += node->val;

                if(node->left)
                {
                    q.push(node->left);
                }
                
                if(node->right)
                {
                    q.push(node->right);
                }
            }
        }
        
        return sum;
    }
};

//time complexity: O(n), since each element is visited once
//space complexity: O(n), since the max queue size will be O(n), so it will be O(n)