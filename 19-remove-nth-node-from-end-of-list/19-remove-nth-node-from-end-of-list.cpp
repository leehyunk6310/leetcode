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
// 투 포인터
// ptr1을 n칸만큼 next 시킨다.
// ptr1과 ptr2를 같이 next로 이동
// ptr1의 next가 null인 경우를 체크한다
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        
        for (int i=0; i<n; i++)
        {
            ptr1 = ptr1->next;
            if (!ptr1)
                return head->next;
        }
        
        while (ptr1->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr2->next->next;
        
        return head;
    }
};