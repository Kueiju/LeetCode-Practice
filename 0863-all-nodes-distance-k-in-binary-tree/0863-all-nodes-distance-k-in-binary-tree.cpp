/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> hMap;
    void dfs(TreeNode* node, TreeNode* parent)
    {
        if(node == nullptr)
            return;

        hMap[node] = parent; //first difficult
        dfs(node->left, node);
        dfs(node->right, node);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        dfs(root, nullptr);

        queue<TreeNode*> queue;
        unordered_set<TreeNode*> seen; //second difficult

        queue.push(target);
        seen.insert(target);

        int distance = 0;
        while(!queue.empty() && distance < k)
        {
            int currentlength = queue.size(); //difficult 3
            for(int i = 0; i < currentlength; i++)
            {
                TreeNode* tmp = queue.front();
                queue.pop();

                for(TreeNode* neighbor : {tmp->left, tmp->right, hMap[tmp]})
                {
                    if(neighbor != nullptr && seen.find(neighbor) == seen.end())
                    {
                        seen.insert(neighbor);
                        queue.push(neighbor);
                    }
                }
            }

            distance++;
        }

        vector<int> ans;

        while(!queue.empty())
        {
            TreeNode* node = queue.front(); //difficult 4
            queue.pop();
            ans.push_back(node->val); //difficult 5
        }
        
        return ans;
    }
};