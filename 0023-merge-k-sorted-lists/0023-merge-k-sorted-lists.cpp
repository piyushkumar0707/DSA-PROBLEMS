#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for the min-heap
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        // Push the head of each non-empty list into the heap
        for (ListNode* node : lists) {
            if (node) minHeap.push(node);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};