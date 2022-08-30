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
        // 10:31
        int ans = 0;
        queue<TreeNode*> q;
        
        if (root->left == NULL && root->right == NULL)
            return root->val;
        
        q.push(root);
        while(q.size())
        {            
            int q_size = q.size();
            ans = 0;
            
            for (int i=0; i<q_size; i++)
            {
                
                TreeNode* t = q.front();
                ans += t->val;
                q.pop();                                                
                if (t->left)
                {
                    q.push(t->left);                    
                }                    
                if (t->right)
                {
                    q.push(t->right);                    
                }                          
            }           
        }
        
        return ans;
    }
};