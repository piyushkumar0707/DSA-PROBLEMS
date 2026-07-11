class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCount=0;
        int m= grid.size(), n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)freshCount++;
            }
        }
        if(freshCount==0)return 0;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int time=0;
        while(!q.empty()){
            int size=q.size();
            time++;
            for(int i=0; i<size; i++){
                auto[x,y]=q.front();
                q.pop();

                for(int d=0; d<4; d++){
                    int nx= x+ dx[d], ny=y+dy[d];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        freshCount--;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return freshCount==0? time-1:-1;
    }
};