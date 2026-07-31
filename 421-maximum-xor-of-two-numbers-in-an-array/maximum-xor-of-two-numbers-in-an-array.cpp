class Node{
public:
    Node* links[2];
    
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    
    void put(int bit, Node* node){
        links[bit]=node;
    }
    
    Node* get(int bit){
        return links[bit];
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root=new Node();
        
        // insert all numbers
        for(int num:nums){
            Node* node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        
        int maxi=0;
        
        // find max xor
        for(int num:nums){
            Node* node=root;
            int curr=0;
            
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                
                // want opposite bit
                if(node->containsKey(1-bit)){
                    curr = curr | (1<<i);
                    node=node->get(1-bit);
                }
                else{
                    node=node->get(bit);
                }
            }
            
            maxi=max(maxi,curr);
        }
        
        return maxi;
    }
};