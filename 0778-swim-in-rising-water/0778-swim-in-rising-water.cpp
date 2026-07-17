class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int,int>>, greater<>>pq;
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto[time, r,c]= pq.top(); pq.pop();
            if(r==m-1 && c==n-1)return time;
            if(time> dist[r][c])continue;

            if(r+1<m){
                int newTime= max(time, grid[r+1][c]);
                if(newTime <dist[r+1][c]){
                dist[r+1][c]= newTime;
                pq.push({newTime, r+1, c});
                }
            }if(r-1>=0){
                int newTime= max(time, grid[r-1][c]);
                if(newTime< dist[r-1][c]){
                    dist[r-1][c]=newTime;
                    pq.push({newTime, r-1, c});

                }
            }if(c+1 <n){
                int newTime= max(time, grid[r][c+1]);
                if(newTime< dist[r][c+1]){
                    dist[r][c+1]=newTime;
                    pq.push({newTime, r, c+1});
                }
            }if(c-1>=0){
                int newTime= max(time, grid[r][c-1]);
                if(newTime < dist[r][c-1]){
                    dist[r][c-1]=newTime;
                    pq.push({newTime, r, c-1});
                }
            }
        }return dist[m-1][n-1];
        
    }
};