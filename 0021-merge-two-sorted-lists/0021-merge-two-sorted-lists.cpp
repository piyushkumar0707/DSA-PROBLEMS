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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy= new ListNode(-1);
        ListNode *tail= dummy;
        while(list1!= NULL && list2!=NULL){
            if(list1->val<list2->val){
                tail->next=list1;
                list1=list1->next;
            }else {tail->next=list2;
                   list2=list2->next; 
                }
                tail=tail->next;
        }
        if(list1!=NULL)tail->next=list1;
        else tail->next=list2;

        return dummy->next;
    }
};