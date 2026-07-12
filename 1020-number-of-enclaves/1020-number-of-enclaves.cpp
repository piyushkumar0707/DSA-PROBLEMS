class Solution {
public:

    void dfs(vector<vector<int>>& grid, int r, int c){
        int m= grid.size();
        int n= grid[0].size();
        if(r<0 || r>=m || c<0 || c>=n)return;
        if(grid[r][c]!=1)return; //inme dfs lgana hi nhi hai
        grid[r][c]=2; //safe hai inhe count nhi karne ye boundary pe hai

        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r,c+1);
        dfs(grid, r,c-1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<m; i++){
            if(grid[i][0]==1)dfs(grid, i,0);
            if(grid[i][n-1]==1)dfs(grid, i,n-1);

        }for(int j=0; j<n;j++){
            if(grid[0][j]==1)dfs(grid, 0,j);
            if(grid[m-1][j]==1)dfs(grid, m-1,j);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j]==1)count++; //unsafe count karne hai jo boundary se connected nhi hai
            }
        }
        return count;
        
    }
};