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
    // 11:10
    TreeNode* increasingBST(TreeNode* root) {
        queue<TreeNode*> q;                
                
        
        if (root->left)
            dfs(root->left, q);        
        q.push(root);
        if (root->right)
            dfs(root->right, q);        
        
        TreeNode* t = new TreeNode(q.front()->val);
        TreeNode* ans = t;
        while (!q.empty())
        {
            q.pop();
            if (q.empty())
                break;
            t->right = new TreeNode(q.front()->val);
            t = t->right;
        }
        
        
        return ans;
    }
    
    void dfs(TreeNode* root, queue<TreeNode*>& q)
    {
        if (!root->left && !root->right)
        {
            q.push(root);
            return;
        }
        
        if (root->left)
            dfs(root->left, q);
        
        q.push(root);
        
        if (root->right)
            dfs(root->right, q);  
        
        
    }
};