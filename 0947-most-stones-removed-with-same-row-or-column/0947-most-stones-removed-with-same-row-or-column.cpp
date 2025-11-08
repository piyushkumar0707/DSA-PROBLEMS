class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> parent;

        // Find with path compression
        function<int(int)> find = [&](int x) {
            if (parent.find(x) == parent.end()) parent[x] = x;
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        // Union by root
        auto unite = [&](int x, int y) {
            parent[find(x)] = find(y);
        };

        for (auto& stone : stones) {
            // Use bitwise NOT to distinguish rows and columns
            unite(stone[0], ~stone[1]);
        }

        unordered_set<int> uniqueRoots;
        for (auto& stone : stones) {
            uniqueRoots.insert(find(stone[0]));
        }

        return stones.size() - uniqueRoots.size();
    }
};