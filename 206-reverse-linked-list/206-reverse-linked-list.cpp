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
    ListNode* reverseList(ListNode* head) {
        vector<int> v;        
        ListNode* temp;
        ListNode* ans;
        ListNode* node = new ListNode();
        
        while (head != nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }
        
        reverse(v.begin(), v.end());                       
                
        ans = node;
        
        if(v.empty())
            return nullptr;
        
        for (int i=0; i<v.size(); i++)
        {
            node->val = v[i];
            if (i+1 >= v.size()) break;
            
            temp = new ListNode();
            node->next = temp;
            node = node->next;
            
        }
        return ans;
    }
};