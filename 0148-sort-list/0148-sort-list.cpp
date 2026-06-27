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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head; //Base case: empty ya single node — already sorted
        ListNode* mid= findMiddle(head);  //Step 1: middle dhundo
        ListNode* secondHalf= mid->next; // Step 2: split karo — List B ka head save karo PEHLE, fir tod
        mid->next= NULL;  // List A ko List B se disconnect kar diya

        ListNode* leftSorted= sortList(head);
        ListNode* rightSorted= sortList(secondHalf);

         // Step 3: dono halves recursively sort karo
        return mergeTwoLists(leftSorted, rightSorted);
        
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* fast= head;
        ListNode* slow= head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }return slow;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* dummy= new ListNode(-1);
        ListNode* tail= dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                tail->next=list1;
                list1=list1->next;
            }else{
                tail->next= list2;
                list2=list2->next;
            }tail=tail->next;
        }
        if(list1!=NULL)tail->next=list1;
        else tail->next=list2;
        return dummy->next;
    }
};