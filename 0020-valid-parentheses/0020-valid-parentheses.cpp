class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char ch : s) {
            if (bracketMap.count(ch)) {
                // If it's a closing bracket
                if (st.empty() || st.top() != bracketMap[ch]) {
                    return false;
                }
                st.pop();
            } else {
                // It's an opening bracket
                st.push(ch);
            }
        }

        return st.empty();
    }
};