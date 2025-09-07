#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        int maxFreq = 0;

        // Count frequency of each task
        for (char task : tasks) {
            freq[task]++;
            maxFreq = max(maxFreq, freq[task]);
        }

        // Count how many tasks have the max frequency
        int maxCount = 0;
        for (auto& entry : freq) {
            if (entry.second == maxFreq) {
                maxCount++;
            }
        }

        // Calculate the minimum intervals
        int partCount = maxFreq - 1;
        int partLength = n + 1;
        int emptySlots = partCount * partLength + maxCount;

        return max((int)tasks.size(), emptySlots);
    }
};