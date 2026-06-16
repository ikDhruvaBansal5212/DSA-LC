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
        Node* temp=head;
        Node* copynode;

        while(temp!=NULL){
            copynode=new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            temp=temp->next->next;
        }

        temp=head;
        while(temp!=NULL){
            copynode=temp->next;
            copynode->random = temp->random ? temp->random->next : NULL;
            temp=temp->next->next;
        }

        Node* dummynode=new Node(-1);
        Node* res=dummynode;
        temp=head;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummynode->next;
    }
};