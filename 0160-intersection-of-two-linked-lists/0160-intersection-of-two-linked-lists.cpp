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
        ListNode* ptrA= headA;
        ListNode* ptrB=headB;
        while(ptrA!=ptrB){
            ptrA= (ptrA==NULL)?headB: ptrA->next;
            ptrB=(ptrB==NULL)? headA: ptrB->next;
        }return ptrA;
    }
};