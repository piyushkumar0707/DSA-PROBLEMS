class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreater;  // value -> next greater value
        stack<int> st;
        
        // Step 1: nums2 ko right-to-left traverse karo
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int current = nums2[i];
            
            // chhote/equal elements ko pop karo (useless hai)
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }
            
            // jo bacha stack mein top pe, wahi next greater hai
            if (st.empty()) {
                nextGreater[current] = -1;
            } else {
                nextGreater[current] = st.top();
            }
            
            st.push(current);  // current ko push kar do future ke liye
        }
        
        // Step 2: nums1 ke har element ke liye map se lookup karo
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};