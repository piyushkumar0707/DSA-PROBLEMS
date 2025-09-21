class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int prevEnd = INT_MIN;

        // Step 2: Count non-overlapping intervals
        for (const auto& interval : intervals) {
            if (interval[0] >= prevEnd) {
                prevEnd = interval[1]; // Accept this interval
            } else {
                count++; // Overlapping, so remove it
            }
        }

        return count;
    }
};