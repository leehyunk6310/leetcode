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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // 7:36
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> tmp;
        
        if (!root)
            return {};
        
        q.push(root);
        
        while (q.size())
        {
            int qSize = q.size();
            
            for (int i=0; i<qSize; i++)
            {
                TreeNode* t = q.front();
                
                tmp.push_back(t->val);
                
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                
                q.pop();
            }
            
            ans.push_back(tmp);
            tmp.clear();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};