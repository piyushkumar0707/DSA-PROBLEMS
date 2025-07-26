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
    ListNode *getIntersectionNode(ListNode *firstHead, ListNode *secondHead) {
        if(firstHead==NULL || secondHead==NULL) return NULL;
        ListNode*temp1=firstHead;
        ListNode*temp2=secondHead;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2)return temp1;
            if(temp1==NULL)temp1=secondHead; 
            if(temp2==NULL)temp2=firstHead;
      }return temp1;
        
    } 
};