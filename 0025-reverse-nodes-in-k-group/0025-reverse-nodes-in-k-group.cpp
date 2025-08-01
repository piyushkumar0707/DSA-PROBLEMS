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
    // Helper to get the k-th node from current node
ListNode* getKthNode(ListNode* temp, int k) {
    k -= 1;
    while (temp != NULL && k > 0) {
        temp = temp->next;
        k--;
    }
    return temp;
}

// Helper to reverse a linked list segment
ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Main function to reverse nodes in k-group
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* prevLast = NULL;

    while (temp != NULL) {
        ListNode* kthNode = getKthNode(temp, k);
        if (kthNode == NULL) {
            // Not enough nodes to reverse, link remaining part
            if (prevLast) prevLast->next = temp;
            break;
        }

        ListNode* nextNode = kthNode->next;
        kthNode->next = NULL; // Isolate the k-group

        // Reverse the isolated k-group
        ListNode* reversedHead = reverseLinkedList(temp);

        // Connect previous part to reversed head
        if (temp == head) {
            head = reversedHead;
        } else {
            prevLast->next = reversedHead;
        }

        // Update prevLast to the tail of reversed segment
        prevLast = temp;
        temp = nextNode;
    }

    return head;
}
};