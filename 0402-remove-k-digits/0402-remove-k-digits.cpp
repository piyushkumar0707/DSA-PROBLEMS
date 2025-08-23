class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;

        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }

        // If k > 0, remove remaining digits from the end
        stack.resize(stack.size() - k);

        // Remove leading zeros
        int start = 0;
        while (start < stack.size() && stack[start] == '0') {
            start++;
        }

        string result = stack.substr(start);
        return result.empty() ? "0" : result;
    }
};