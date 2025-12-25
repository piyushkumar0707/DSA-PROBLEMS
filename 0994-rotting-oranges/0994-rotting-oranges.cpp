class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Queue stores {row, col} coordinates
        queue<pair<int, int>> q;
        int freshOranges = 0;

        // STEP 1: PRE-PROCESSING (The "Manager" Setup)
        // We need to find all starting points (rotten oranges) and count fresh ones
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j}); // Push all initially rotten oranges
                } else if(grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        // Edge Case: If there are no fresh oranges to begin with, 0 minutes needed.
        if(freshOranges == 0) return 0;

        int minutes = 0;
        
        // Direction arrays for moving Up, Right, Down, Left
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        // STEP 2: STANDARD BFS (The Worker)
        while(!q.empty()) {
            int size = q.size();
            bool infected_something = false;

            // Process one "minute" (all oranges currently in queue)
            for(int i = 0; i < size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                // Try all 4 neighbors
                for(int k = 0; k < 4; k++) {
                    int nrow = r + dRow[k];
                    int ncol = c + dCol[k];

                    // Check boundaries and if the neighbor is a FRESH orange
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                       grid[nrow][ncol] == 1) {
                        
                        grid[nrow][ncol] = 2; // Mark as rotten
                        q.push({nrow, ncol}); // Add to queue for next minute
                        freshOranges--;       // Decrease fresh count
                        infected_something = true;
                    }
                }
            }
            
            // Only increment time if we actually infected a new orange
            if(infected_something) minutes++;
        }

        // STEP 3: FINAL CHECK
        // If fresh oranges still remain, it's impossible (-1)
        if(freshOranges > 0) return -1;
        
        return minutes;
    }
};