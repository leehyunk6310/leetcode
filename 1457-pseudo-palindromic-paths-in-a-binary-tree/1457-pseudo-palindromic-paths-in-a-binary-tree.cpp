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
    int answer = 0;
    unordered_map<int, int> m;
    
    int pseudoPalindromicPaths (TreeNode* root) {
        // root -> leaf 의 노드값을 저장하는 unordered_map을 구한다.
        // map을 순회하면서 홀수인 값이 2회 이상이면 not palindrom
        
        dfs(root);
        
        return answer;
    }
    
    void dfs(TreeNode* root)
    {
        if (!root)
            return;
        
        m[root->val]++;
        
        if (!root->left && !root->right)
        {
            int odd = 0;            
            for (auto mm : m)
            {
                if (mm.second % 2 != 0)
                    odd++;
                if (odd >= 2)
                {
                    break;
                }
            }
            if (odd <= 1)
                answer++;
        }
        
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        
        m[root->val]--;
    }
    
//     bool isPalindrom(unordered_map<int, int> m)
//     {
//         int odd = 0;
//         for (auto mm : m)
//         {
//             if (mm.second % 2 != 0)
//                 odd++;
//             if (odd >= 2)
//                 return false;
//         }
        
        
//         return true;
//     }
};