#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build the graph as an adjacency list
        vector<vector<pair<int, int>>> graph(n + 1); // 1-indexed
        for (const auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
        }

        // Step 2: Min-heap priority queue for Dijkstra: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.emplace(0, k);

        // Step 3: Dijkstra's algorithm
        while (!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();
            if (time > dist[node]) continue;

            for (auto& [nei, wt] : graph[node]) {
                if (dist[nei] > time + wt) {
                    dist[nei] = time + wt;
                    pq.emplace(dist[nei], nei);
                }
            }
        }

        // Step 4: Find the maximum time to reach all nodes
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1; // unreachable node
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};