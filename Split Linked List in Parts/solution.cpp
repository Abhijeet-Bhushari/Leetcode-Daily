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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int len = 0, mod;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        mod = len%k;
        temp = head;
        int div = len/k + (mod>0) - 1;
        if(mod>0) mod--;
        ListNode* temp2 = temp;
        int rem = k;
        while(rem-ans.size()>0){
            if(div>0){
                div--;
                temp2 = temp2->next;
            }
            else if(temp2 != NULL){
                ListNode* temp3 = temp2->next;
                temp2->next = NULL;
                ans.push_back(temp);
                temp = temp3;
                temp2 = temp;
                div = len/k + (mod>0) - 1;
                if(mod>0) mod--;                
            }
            else{
                ans.push_back(NULL);
            }
        }
        return ans;
    }
};