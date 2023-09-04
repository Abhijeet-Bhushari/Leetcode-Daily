class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next == NULL) return false;
        ListNode* slow=head, *fast=head->next;
        while(fast!=NULL && fast->next!=NULL && slow!=fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast==slow) return true;
        return false;
    }
};