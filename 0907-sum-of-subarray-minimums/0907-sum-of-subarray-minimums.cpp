class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> ple(n), nle(n);
        stack<int> s;

        // Previous Less Element
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            ple[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack for Next Less Element
        while (!s.empty()) s.pop();

        // Next Less Element
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            nle[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculate result
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            result = (result + arr[i] * left * right) % MOD;
        }

        return result;
    }
};