/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA= getLength(headA);
        int lenB= getLength(headB);

        ListNode* ptrA= headA;
        ListNode* ptrB= headB;

        if(lenA> lenB){
            for(int i=0; i<lenA-lenB; i++)ptrA=ptrA->next;

        }else{
            for(int i=0; i<lenB-lenA; i++)ptrB= ptrB->next;
        }

        while(ptrA!=ptrB){
            ptrA=ptrA->next;
            ptrB=ptrB->next;
        }
        return ptrA;
        
    }
     int getLength(ListNode*head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;

        }return len;

    }
};