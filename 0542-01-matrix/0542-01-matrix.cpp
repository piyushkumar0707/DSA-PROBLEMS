class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n= mat[0].size();
        vector<vector<int>>dist(m,vector<int>(n,-1));
        queue<pair<int,int>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            auto[x,y]= q.front();
            q.pop();

            for(int d=0; d<4; d++){
                int nx= x+dx[d], ny=y+dy[d];
                if(nx>=0 && nx<m && ny>=0 && ny<n && dist[nx][ny]==-1){
                    dist[nx][ny]= dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }return dist;
        
    }
};