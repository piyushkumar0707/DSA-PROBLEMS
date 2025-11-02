#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;

        // Min-heap priority queue: (effort, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);

        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto [currEffort, x, y] = pq.top();
            pq.pop();

            if (x == rows - 1 && y == cols - 1) return currEffort;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dirX[d];
                int ny = y + dirY[d];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                    int nextEffort = max(currEffort, abs(heights[x][y] - heights[nx][ny]));
                    if (nextEffort < effort[nx][ny]) {
                        effort[nx][ny] = nextEffort;
                        pq.emplace(nextEffort, nx, ny);
                    }
                }
            }
        }

        return 0; // Should never reach here
    }
};