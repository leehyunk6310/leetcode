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
    vector<int> rightSideView(TreeNode* root) {
        // 10:38
        // 1. 기존 것을 팝 하고 큐에다가 bfs를 활용하여 다 집어넣음
        // 2. 큐의 끝에 있는것을 ans에 넣고 근접 노드 넣은 후 기존 사이즈만큼 팝
        vector<int> ans;
        queue<TreeNode*> q;
        
        if (!root)
            return {};
        
        q.push(root);
        ans.push_back(root->val);
        
        while (q.size())
        {
            int q_size = q.size();
            for (int i=0; i<q_size; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            if (q.empty())
                break;
            
            ans.push_back(q.back()->val);
            
        }
        
        return ans;
        
        
    }
};