class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];

            // Maintain a decreasing stack
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }

            // If stack is empty, no greater element to the right
            nextGreater[num] = st.empty() ? -1 : st.top();

            // Push current number to stack
            st.push(num);
        }

        // Build the result for nums1 using the map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};