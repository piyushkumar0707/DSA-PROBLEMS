class Solution {
public:


    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c, int prevHeight){
        int m=heights.size();
        int n=heights[0].size();
        if(r<0 || r>=m || c<0 || c>=n)return ;
        if(visited[r][c])return;
        if(heights[r][c]<prevHeight)return; //reverse flow condition
        visited[r][c]=true;

        dfs(heights, visited, r+1, c, heights[r][c]);
        dfs(heights, visited, r-1, c, heights[r][c]);
        dfs(heights, visited, r,c+1, heights[r][c]);
        dfs(heights, visited, r, c-1, heights[r][c]);

    }




    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m= heights.size();
        int n=heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        //for pacific top row + left colm
        for(int i=0; i<m;i++)dfs(heights, pacific,i,0,0);
        for(int j=0; j<n;j++)dfs(heights, pacific,0,j,0);

        //for atlantic bottom row+ right col
        for(int i=0; i<m;i++)dfs(heights, atlantic,i,n-1,0);
        for(int j=0; j<n; j++)dfs(heights, atlantic, m-1,j,0);

        vector<vector<int>>result;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j])result.push_back({i,j});
            }
        }return result;
        
    }
};