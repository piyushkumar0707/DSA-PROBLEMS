class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c){
        int m= grid.size();
        int n= grid[0].size();
        if(r<0 || r>=m || c<0 || c>=n)return 0;
        if(grid[r][c]==0)return 0; //already visited
        grid[r][c]=0;

        return 1+dfs(grid, r+1, c )+
        dfs(grid, r-1,c)+
        dfs(grid, r, c+1)+
        dfs(grid, r, c-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int maxArea=0;
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    maxArea= max(maxArea, dfs(grid, i,j));
                }
            }
        }return maxArea;

        
    }
};