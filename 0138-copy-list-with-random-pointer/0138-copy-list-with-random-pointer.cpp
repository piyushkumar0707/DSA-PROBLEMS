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
        if(head==NULL)return NULL;
        unordered_map<Node*, Node*>mp;

        // Pass1: make clone nodes, store mappings
        Node* curr=head;
        while(curr!=NULL){
            mp[curr]=new Node(curr->val);
            curr=curr->next;
        }
        //Pass 2 links set karo
        curr=head;
        while(curr!=NULL){
            mp[curr]->next= (curr->next!=NULL)?mp[curr->next]:NULL;
            mp[curr]->random= (curr->random!=NULL)?mp[curr->random]:NULL;
            curr=curr->next;
        }
        return mp[head];


    }
};