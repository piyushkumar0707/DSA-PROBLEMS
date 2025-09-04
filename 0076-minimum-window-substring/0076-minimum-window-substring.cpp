#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // Step 1: Frequency map for characters in t
        unordered_map<char, int> t_count;
        for (char c : t) t_count[c]++;

        int required = t_count.size(); // Number of unique characters to match
        int left = 0, right = 0, formed = 0;
        unordered_map<char, int> window_count;

        // Result variables: (window length, left, right)
        int min_len = INT_MAX;
        int min_left = 0;

        while (right < s.size()) {
            char c = s[right];
            window_count[c]++;

            // Check if current character fulfills the requirement
            if (t_count.count(c) && window_count[c] == t_count[c]) {
                formed++;
            }

            // Try to shrink the window from the left
            while (left <= right && formed == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_left = left;
                }

                // Remove leftmost character
                char left_char = s[left];
                window_count[left_char]--;
                if (t_count.count(left_char) && window_count[left_char] < t_count[left_char]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};