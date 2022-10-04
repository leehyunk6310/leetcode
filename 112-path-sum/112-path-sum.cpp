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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 4:33
        // targetSum에서 방문한 노드의 값을 뺀다.
        if (!root)
            return 0;
        
        targetSum -= root->val;
        
        // 리프노드에서 targetSum이 0이 되면 true 반환
        if (root->left == NULL && root->right == NULL && targetSum == 0)
            return true;
        else if (root->left == NULL && root->right == NULL && targetSum != 0)
            return false;
        
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
        
    }
    
    
};