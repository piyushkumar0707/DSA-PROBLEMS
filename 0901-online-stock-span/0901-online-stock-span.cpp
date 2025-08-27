class StockSpanner {
private:
    // Stack stores pairs of (price, span)
    stack<pair<int, int>> st;

public:
    StockSpanner() {
        // No initialization needed beyond the stack
    }

    int next(int price) {
        int span = 1;

        // Pop all prices less than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price and its span
        st.push({price, span});
        return span;
    }
};