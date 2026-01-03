class Solution {
private:
    // STANDARD DFS HELPER (The Worker)
    // Marks "Safe" 'O's by turning them into a temporary character '#'
    void dfs(int row, int col, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Base Case: Check bounds or if it's not an 'O' (either 'X' or already marked '#')
        if(row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 'O') {
            return;
        }

        // Mark the current cell as visited/safe
        board[row][col] = '#';

        // Traverse 4 directions
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        for(int k = 0; k < 4; k++) {
            dfs(row + dRow[k], col + dCol[k], board);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        // STEP 1: Process Boundaries (The Manager)
        // We only start DFS from 'O's located on the borders.
        
        // Check First and Last Row
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') dfs(0, j, board);       // First row
            if(board[n-1][j] == 'O') dfs(n-1, j, board);   // Last row
        }
        
        // Check First and Last Column
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') dfs(i, 0, board);       // First column
            if(board[i][m-1] == 'O') dfs(i, m-1, board);   // Last column
        }

        // STEP 2: Capture and Restore
        // Now, the grid has three types of cells:
        // 'X': Walls
        // '#': Safe 'O's (connected to border)
        // 'O': Trapped 'O's (internal, unsurrounded)
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X'; // Capture the trapped ones
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O'; // Restore the safe ones
                }
            }
        }
    }
};