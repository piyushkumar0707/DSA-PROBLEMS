class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m= grid.size();
        int n= grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1')count++;
                dfs(i,j, grid);

            }
        }return count;
    }
    void dfs(int r, int c, vector<vector<char>>& grid){
        int m= grid.size(), n=grid[0].size();
        if(r<0 || r>=m  ||c<0 || c>=n)return;
        if(grid[r][c]=='0')return;
        grid[r][c]='0';

        dfs(r+1, c, grid);
        dfs(r-1, c, grid);
        dfs(r, c+1, grid);
        dfs(r,c-1, grid);

    }
};
