class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // c == '*'
                low--;   // treat '*' as ')'
                high++;  // treat '*' as '('
            }

            // Clamp low to zero
            if (low < 0) low = 0;

            // If high < 0, too many ')'
            if (high < 0) return false;
        }

        // If low == 0, all open '(' can be matched
        return low == 0;
    }
};