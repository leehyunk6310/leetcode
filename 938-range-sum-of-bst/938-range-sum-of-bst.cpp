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
    int sum = 0;
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        solve(root, low, high);
        
        return sum;
    }
    
    int solve(TreeNode* p, int low, int high)
    {
        if (p == NULL)
            return 0;
        if (p->val >= low && high >= p->val)
            sum += p->val;
        
        return solve(p->left, low, high) || solve(p->right, low, high);
    }
};