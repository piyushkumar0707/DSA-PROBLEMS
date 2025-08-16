class MinStack {
private:
    stack<int> s;
    stack<int> minS;

public:
    MinStack() {
        // No initialization needed beyond stack creation
    }

    void push(int val) {
        s.push(val);
        // Push the new min value onto minS
        if (minS.empty() || val <= minS.top()) {
            minS.push(val);
        } else {
            minS.push(minS.top());
        }
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
            minS.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};