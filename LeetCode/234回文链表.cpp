/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == NULL)
            return true;

        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* p = slow->next;
        slow->next = NULL;

        ListNode* q;
        ListNode* pre = NULL;
        while(p!=NULL){
            q = p->next;
            p->next = pre;
            pre = p;
            p = q;
        }

        p = head;
        q = pre;
        while(p!=NULL && q!=NULL){
            if(p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        return true;

    }
};
