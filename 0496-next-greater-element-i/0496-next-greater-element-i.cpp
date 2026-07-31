class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    vector<int> nge(n, -1);      // nums2 ka next-greater result
    stack<int> st;                // indices store honge

    // Step 1: nums2 pe monotonic stack chalao
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums2[st.top()] < nums2[i]) {
            int idx = st.top();
            st.pop();
            nge[idx] = nums2[i];
        }
        st.push(i);
    }

    // Step 2: value -> next_greater map banao
    unordered_map<int, int> valToNGE;
    for (int i = 0; i < n; i++) {
        valToNGE[nums2[i]] = nge[i];
    }

    // Step 3: nums1 ke har element ke liye lookup
    vector<int> ans;
    for (int num : nums1) {
        ans.push_back(valToNGE[num]);
    }

    return ans;
}
};