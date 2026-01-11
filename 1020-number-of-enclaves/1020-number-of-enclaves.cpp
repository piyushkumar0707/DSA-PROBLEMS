class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        // Step 1: Push all boundary land cells into queue
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        // Step 2: BFS to mark all reachable land from boundary
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k=0; k<4; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        // Step 3: Count enclaves (land not visited)
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};