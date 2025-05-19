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
            return vector<int>{};

        vector<int> ans;
        queue<TreeNode*> qe;
        qe.push(root);

        while(!qe.empty())
        {
            int currentlevel = qe.size();
            int maxval = INT_MIN;

            for(int i = 0; i < currentlevel; i++)
            {
                TreeNode* node = qe.front();
                qe.pop();

                maxval = max(maxval, node->val);

                if(node->left)
                    qe.push(node->left);

                if(node->right)
                    qe.push(node->right);
            }

            ans.push_back(maxval);
        }
        
        return ans;
    }
};


//time complexity: O(n), every node will be visited once
//space complexity: O(n), since the max queue size will be O(n) ~= O(n/2) in each level, plus the vector element (each time 1 element, max O(n)), so it is O(n)
