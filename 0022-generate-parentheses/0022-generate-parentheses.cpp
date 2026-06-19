class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;          // yahi result accumulate hoga
        solve("", 0, 0, n, result);      // empty string se start, 0 open, 0 close
        return result;
    }

    void solve(string currentString, int openCount, int closeCount, int n, vector<string>& result) {
        // Base case: jab string ki length 2*n ho gayi, matlab pura ban gaya
        if (currentString.size() == 2 * n) {
            result.push_back(currentString);
            return;
        }

        // Choice 1: '(' daalo agar abhi tak n se kam open kiye hai
        if (openCount < n) {
            solve(currentString + "(", openCount + 1, closeCount, n, result);
        }

        // Choice 2: ')' daalo agar open kiye hue se kam close kiye hai
        if (closeCount < openCount) {
            solve(currentString + ")", openCount, closeCount + 1, n, result);
        }
    }
};