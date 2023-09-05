/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* head2 = new Node(0);
        Node* temp2 = head2, *temp = head;
        
        map<Node*, Node*> mp;
        
        while(temp!=NULL){
            mp[temp] = temp2;
            temp2->val = temp->val;
            if(temp->next!=NULL) temp2->next = new Node(0);
            temp2 = temp2->next;
            temp = temp->next;
        }
        
        // O(N) space complexity O(N) time complexity solution
        temp2 = head2;
        temp = head;
        while(temp!=NULL){
            if(temp->random != NULL){
                temp2->random = mp[temp->random];
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return head2;
        
        // O(1) space complexity O(N*N) time complexity solution
        temp2 = head2;
        temp = head;
        Node* track1 = head, *track2 = head2;
        while(temp!=NULL){
            if(temp->random !=NULL){
                while(track1!=temp->random){
                    track1=track1->next;
                    track2=track2->next;
                }
                temp2->random = track2;
                track2 = head2;
                track1 = head;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        
        return head2;
    }
};