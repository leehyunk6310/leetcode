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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if (depth == 1)
        {
            TreeNode* left = root;
            
            root = new TreeNode(val);
            
            root->left = left;
        }
        else
            solve(root, val, depth, 0);
        
        return root;
    }
    
    void solve(TreeNode* node, int val, int depth, int count)
    {
        count++;
        if (count == depth - 1)
        {
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            
            node->left->left = left;
            node->right->right = right;
        }
        
        // 좌측 서브 그래프 우측 서브 그래프 탐색
        if (node->left) solve(node->left, val, depth, count);
        if (node->right) solve(node->right, val, depth, count);
    }
};