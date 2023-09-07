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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int start = 0, end = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* t1 = dummy, *t2 = dummy;
        while(start<left - 1){
            t1 = t1->next;
            start++;
        }
        while(end<right+1){
            t2 = t2->next;
            end++;
        }
        ListNode* pre = t1->next, *cur, *nex = NULL;
        cur = pre->next;
        while(cur!=NULL && cur!=t2){
            if(cur!=NULL) nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        t1->next->next = cur;
        t1->next = pre;
        return dummy->next;
    }
};