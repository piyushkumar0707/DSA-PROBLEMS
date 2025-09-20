class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& last = merged.back();
            vector<int>& current = intervals[i];

            // Check for overlap
            if (current[0] <= last[1]) {
                // Merge by updating the end time
                last[1] = max(last[1], current[1]);
            } else {
                // No overlap, add current interval
                merged.push_back(current);
            }
        }

        return merged;
    }
};