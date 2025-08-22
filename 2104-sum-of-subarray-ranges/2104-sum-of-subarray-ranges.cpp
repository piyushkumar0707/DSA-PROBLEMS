class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return getSum(nums, true) - getSum(nums, false);
    }

private:
    long long getSum(const vector<int>& nums, bool isMax) {
        int n = nums.size();
        stack<int> st;
        long long res = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || 
                   (isMax && nums[i] > nums[st.top()]) || 
                   (!isMax && nums[i] < nums[st.top()]))) {
                int j = st.top(); st.pop();
                int k = st.empty() ? -1 : st.top();
                long long left = j - k;
                long long right = i - j;
                res += (long long)nums[j] * left * right;
            }
            st.push(i);
        }

        return res;
    }
};