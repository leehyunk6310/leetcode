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
        ListNode* temp = new ListNode();
        temp = head;
        vector<int> v;
        int count = 0;
        int half = 0;
        
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        half = count/2;
        
        if (count%2 == 0)
        {
            while(half)
            {
                v.push_back(head->val);
                head = head->next;
                half--;
            }
        }
        else
        {
            while(half)
            {
                v.push_back(head->val);
                head = head->next;
                half--;
            }
            head = head->next;
        }
        
        // 벡터와 head node의 값들 비교
        while(v.size() != 0)
        {
            if (v.back() == head->val)
            {
                v.pop_back();
                head = head->next;
            }
            else
                return false;
        }
        
        
        
        return true;
    }
};