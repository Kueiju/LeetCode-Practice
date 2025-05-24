class Solution {
private:
    TreeNode *pre = NULL;
    int minabsdiff = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return 0;

        //getMinimumDifference(root->left);
        getMinimumDifference(root->right);
        if( pre )
            if(minabsdiff < 0 || minabsdiff > abs(root->val - pre->val))
                minabsdiff = abs(root->val - pre->val);
        pre = root;
        
        getMinimumDifference(root->left);
        //getMinimumDifference(root->right);

        return minabsdiff;
    }
};