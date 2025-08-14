class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    // Helper to move elements from inStack to outStack
    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {
        // Constructor: nothing to initialize explicitly
    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            transfer();
        }
        int front = outStack.top();
        outStack.pop();
        return front;
    }

    int peek() {
        if (outStack.empty()) {
            transfer();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};