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
        if(head==NULL || head->next==NULL)return true;
        ListNode* middle=findMiddle(head);
        ListNode* secondHalfHead= findReverse(middle->next);

        ListNode* p1= head;
        ListNode* p2= secondHalfHead;
        bool result=true;
        while(p2!=NULL){
            if(p1->val!=p2->val){
                return false;
                break;
            }p1=p1->next;
            p2=p2->next;
        }return result;
        
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* fast= head;
        ListNode* slow= head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }return slow;
    }


    ListNode* findReverse(ListNode* head){
        ListNode* prev= NULL;
        ListNode* curr= head;
        while(curr!=NULL){
            ListNode* nextNode= curr->next;
            curr->next= prev;
            prev= curr;
            curr=nextNode;
        }return prev;
    }
};