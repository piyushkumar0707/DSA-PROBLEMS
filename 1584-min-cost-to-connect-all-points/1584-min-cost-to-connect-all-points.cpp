class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool>visited(n, false);
        vector<int> minDist(n , INT_MAX);
        minDist[0]=0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0,0});

        int totalCost=0;
        while(!pq.empty()){
            auto[cost , node]= pq.top(); pq.pop();

            if(visited[node])continue;
            visited[node]=true;
            totalCost+=cost;

            //sare unvisited points ke sath distance calculate karo
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    int dist= abs(points[node][0]- points[i][0])+abs(points[node][1]-points[i][1]);
                    if(dist< minDist[i]){
                        minDist[i]= dist;
                        pq.push({dist,i});
                    }
                }
            }

        }return totalCost;
    }
};