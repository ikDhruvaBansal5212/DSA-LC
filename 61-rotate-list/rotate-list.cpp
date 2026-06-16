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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *ptr=head;
        if(ptr==NULL || ptr->next==NULL){
            return head;
        }

        int n=1;
        while(ptr->next!=NULL){
            n++;
            ptr=ptr->next;
        }
        k=k%n;
        if(k==0) return head;
        
        ptr->next=head;

        int steps=n-k;
        while(ptr!=NULL && steps>0){
            ptr=ptr->next;
            steps--;
        }
        
        ListNode* newhead=ptr->next;
        ptr->next=NULL;
        return newhead;
    }
};