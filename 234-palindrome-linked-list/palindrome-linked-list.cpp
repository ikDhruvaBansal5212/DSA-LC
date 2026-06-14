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
    bool isPalindrome(ListNode* head) {
        ListNode *sp=head;
        ListNode *fp=head;
        while(fp!=NULL && fp->next!=NULL){
            sp=sp->next;
            fp=fp->next->next;
        }

        ListNode *ptr1=nullptr;
        ListNode *ptr2=sp;
        
        if(fp != nullptr)
        sp = sp->next;

        while(ptr2!=NULL){
            ListNode *temp=ptr2->next;
            ptr2->next=ptr1;
            ptr1=ptr2;
            ptr2=temp;
        }

        ListNode *second=ptr1;
        ListNode *first=head;

        while(second!=NULL){
            if(first->val!=second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;
    }
};