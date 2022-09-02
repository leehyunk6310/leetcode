/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // 7:55
        queue<Node*> q;
        Node* ans = root;
        
        if (!root)
            return {};
        q.push(root);
        
        while (q.size())
        {
            int qSize = q.size();
            
            for (int i=0; i<qSize; i++)
            {
                Node* t = q.front();
                q.pop();
                if (q.size())
                    t->next = q.front();
                if (i==qSize-1)
                    t->next = NULL;
                
                if (t->left)
                {
                    q.push(t->left);
                    q.push(t->right);
                }
                
                
            }
            
        }
        
        return ans;
    }
};