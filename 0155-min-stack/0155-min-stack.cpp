class MinStack {
    stack<pair<int,int>>st;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push({value,value});
        }else{
            int currentMin= min(value, st.top().second);
            st.push({value, currentMin});
        }
        
    }
    
    void pop() {
        st.pop();
        
    }
    
    int top() {
       return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */