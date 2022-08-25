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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 5:00
        // bfs를 써서 풀어야 할 것처럼 보임.
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> v;
        
        if (!root)
            return {};        
        q.push(root);        
        ans.push_back({root->val});        
        
        while(q.size())
        {
            int q_size = q.size();            
            
            for (int i=0; i<q_size; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if (t->left)
                {
                    q.push(t->left);
                    v.push_back(t->left->val);
                }                    
                if (t->right)
                {
                    q.push(t->right);
                    v.push_back(t->right->val);
                }                    
            }                                    
            if (q.size() == 0)
                break;
            ans.push_back(v);
            v.clear();                        
        }
        
        return ans;
    }
};