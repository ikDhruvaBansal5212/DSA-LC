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

        int n=0;
        while(ptr!=NULL){
            n++;
            ptr=ptr->next;
        }
        k=k%n;
        if(k==0) return head;
        
        
        while(k>0){
            ptr=head;
            while(ptr->next->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next->next=head;
            head=ptr->next;
            ptr->next=NULL;
            k--;
        }
        return head;
    }
};