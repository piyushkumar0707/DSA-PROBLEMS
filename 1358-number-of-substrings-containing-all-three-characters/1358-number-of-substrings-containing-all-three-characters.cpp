class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0};  // Tracks counts of 'a', 'b', and 'c'
        int res = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            count[s[right] - 'a']++;

            // Shrink the window from the left while it contains all three characters
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += s.size() - right;  // All substrings from left to end are valid
                count[s[left] - 'a']--;
                left++;
            }
        }

        return res;
    }
};