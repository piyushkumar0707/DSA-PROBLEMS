class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m= heights.size(); int n= heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>pq;

        dist[0][0]=0;
        pq.push({0,0,0}); // {effort, row, col}

        while(!pq.empty()){
            auto[effort, r, c] =pq.top(); pq.pop();
            if(r==m-1 && c==n-1)return effort;
            if(effort > dist[r][c])continue;

            if(r+1< m){
                int newEffort= max(effort, abs(heights[r][c]-heights[r+1][c]));
                if(newEffort< dist[r+1][c]){
                    dist[r+1][c]=newEffort;
                    pq.push({newEffort, r+1, c});
                }

            }
            if(r-1>=0){
                int newEffort= max(effort, abs(heights[r][c]-heights[r-1][c]));
                if(newEffort< dist[r-1][c]){
                    dist[r-1][c]=newEffort;
                    pq.push({newEffort, r-1, c});
                }
            }
            if(c+1<n){
                int newEffort= max(effort, abs(heights[r][c]- heights[r][c+1]));
                if(newEffort<dist[r][c+1]){
                    dist[r][c+1]=newEffort;
                    pq.push({newEffort, r, c+1});
                }
            }
            if(c-1>=0){
                int newEffort= max(effort, abs(heights[r][c]- heights[r][c-1]));
                if(newEffort< dist[r][c-1]){
                    dist[r][c-1]=newEffort;
                    pq.push({newEffort, r, c-1});
                }
            }
        }

        return dist[m-1][n-1];
        
    }
};