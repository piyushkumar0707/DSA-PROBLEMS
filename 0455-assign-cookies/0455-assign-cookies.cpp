#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;  // Pointer to children
        int cookie = 0; // Pointer to cookies

        // Try to satisfy each child with the smallest sufficient cookie
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                // Cookie satisfies the child's greed
                child++;  // Move to next child
            }
            cookie++;  // Move to next cookie regardless
        }

        // 'child' now represents the number of content children
        return child;
    }
};