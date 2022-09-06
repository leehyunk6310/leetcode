/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // 11:10
        vector<vector<int>> ans;        
        queue<Node*> q;
        
        if (!root)
            return {};
        
        q.push(root);
        ans.push_back({root->val});
        
        while (q.size())
        {
            int qSize = q.size();
            vector<int> v;
            for (int i=0; i<qSize; i++)
            {
                Node* n = q.front();
                q.pop();
                
                for (int k=0; k<n->children.size(); k++)
                {
                    q.push(n->children[k]);
                    v.push_back(n->children[k]->val);
                }
            }
            ans.push_back(v);
        }
        ans.pop_back();
        
        return ans;
    }
};