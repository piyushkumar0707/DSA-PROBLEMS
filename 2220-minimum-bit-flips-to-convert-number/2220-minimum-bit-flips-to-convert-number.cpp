class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        int count = 0;
        
        // Count the number of 1s in xorResult
        while (xorResult) {
            count += xorResult & 1;  // Add 1 if the last bit is 1
            xorResult >>= 1;         // Shift right to check the next bit
        }
        
        return count;
    }
};