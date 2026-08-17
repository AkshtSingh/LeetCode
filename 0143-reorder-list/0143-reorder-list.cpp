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
    void reorderList(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
        ListNode *prev=NULL,*curr=slow->next,*next;
        slow->next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* head2=prev,*next1,*next2;
        ListNode* head1=head;
        while(head2!=NULL){
            next1=head1->next;
            next2=head2->next;
            head1->next=head2;
            head2->next=next1;
            head2=next2;
            head1=next1;
        }
    }
};