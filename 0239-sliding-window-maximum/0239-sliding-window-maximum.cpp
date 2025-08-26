

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices of elements not in the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove indices of all elements smaller than current
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);

            // Add to result once the first window is complete
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};