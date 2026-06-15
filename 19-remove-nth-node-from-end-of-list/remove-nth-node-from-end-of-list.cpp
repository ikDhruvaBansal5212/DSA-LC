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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fp=head;
        for(int i=0;i<n;i++){
            fp=fp->next;
        }

         if(fp == NULL) {   // remove head
            return head->next;
        }

        ListNode* sp=head;
        while(fp->next!=NULL){
            sp=sp->next;
            fp=fp->next;
        }

        sp->next=sp->next->next;
        return head;
    }
};