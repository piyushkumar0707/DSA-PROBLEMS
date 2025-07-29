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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        // Step 1: Compute length and find tail
        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Step 2: Effective rotation
        k = k % len;
        if (k == 0) return head;

        // Step 3: Make it circular
        tail->next = head;

        // Step 4: Find new tail (len - k steps ahead from head)
        int stepsToNewTail = len - k;
        ListNode* newTail = head;
        while (--stepsToNewTail) {
            newTail = newTail->next;
        }

        // Step 5: Break the loop and assign new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};