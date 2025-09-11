#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> low; // Max-heap for lower half
    priority_queue<int, vector<int>, greater<int>> high; // Min-heap for upper half

public:
    MedianFinder() {
        // No initialization needed beyond heap declarations
    }

    void addNum(int num) {
        low.push(num); // Step 1: Add to max-heap

        // Step 2: Balance by moving top of low to high
        high.push(low.top());
        low.pop();

        // Step 3: Ensure size invariant: low can have one more than high
        if (low.size() < high.size()) {
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian() {
        if (low.size() > high.size()) {
            return low.top(); // Odd count: top of max-heap
        } else {
            return (low.top() + high.top()) / 2.0; // Even count: average of two middles
        }
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */