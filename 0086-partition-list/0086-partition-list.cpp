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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* temp=head;
        ListNode* less=new ListNode(0),*more=new ListNode(0);
        ListNode* temp1=less,*temp2=more;
        while(temp!=NULL){
            if(temp->val<x){
                temp1->next=new ListNode(temp->val);
                temp1=temp1->next;
            }
            else{
                temp2->next=new ListNode(temp->val);
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        less=less->next;
        more=more->next;
        temp1->next=more;
        if(less==NULL)
            return more;
        else
            return less;
    }
};