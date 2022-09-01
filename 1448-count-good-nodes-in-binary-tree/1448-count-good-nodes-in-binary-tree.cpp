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
    int ans = 0;
    
    int goodNodes(TreeNode* root) {
        // 11:25
        
        int maxVal = root->val;
        
        if (!root->left && !root->right)
            return 1;
        
        solve(root, maxVal);
        
        return ans;
    }
    
    void solve(TreeNode* root, int maxVal)
    {                         
        // maxVal 갱신 및 ans++
        if (root->val >= maxVal)
        {
            maxVal = root->val;
            ans++;
        }
            
        
        if (root->left) solve(root->left, maxVal);
        if (root->right) solve(root->right, maxVal);
        
    }
};