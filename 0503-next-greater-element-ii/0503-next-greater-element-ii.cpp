class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1); // Default to -1
        stack<int> st; // Stack to hold indices

        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n]; // Circular access

            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num;
                st.pop();
            }

            if (i < n) {
                st.push(i); // Only push indices from first pass
            }
        }

        return res;
    }
};