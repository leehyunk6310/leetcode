/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 11:15 시작
        vector<int> v1, v2;
        
        while (head)
        {
            v1.push_back(head->val);
            head = head->next;
        }
        
        v2 = v1;
        reverse(v1.begin(), v1.end());
        
        for (int i=0; i<v1.size(); i++)
        {
            if (v1[i] != v2[i])
                return false;
        }
            
        return true;
            
        
    }
};