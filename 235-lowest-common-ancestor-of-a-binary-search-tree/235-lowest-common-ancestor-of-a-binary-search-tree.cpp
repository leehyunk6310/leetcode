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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 4:30
        
        if (!root)
            return NULL;
        
        // 루트가 p or q 이면 root를 반환
        if (root == p || root == q)
            return root;
        
        // 좌측 노드와 우측 노드를 계산
        TreeNode* Left = lowestCommonAncestor(root->left, p, q);
        TreeNode* Right = lowestCommonAncestor(root->right, p, q);

        // 좌측 노드와 우측 노드가 root의 left,right인 경우
        if (Left!=NULL && Right!=NULL)
            return root;
        // Left가 root인 경우
        else if (Left!=NULL)
            return Left;
        // Right가 root인 경우
        else
            return Right;
            
        
    }
    
    
};