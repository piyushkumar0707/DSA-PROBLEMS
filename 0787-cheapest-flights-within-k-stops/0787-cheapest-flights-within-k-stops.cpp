class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialize distance array with infinity
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Perform k+1 iterations of edge relaxation
        for (int i = 0; i <= k; ++i) {
            vector<int> temp = dist; // Copy current distances
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp; // Update distances
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};