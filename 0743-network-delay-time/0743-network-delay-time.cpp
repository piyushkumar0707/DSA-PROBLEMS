class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // adjacency list bnao
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        //dijkstra
        vector<int>dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        dist[k]=0;
        pq.push({0,k}); //{distance, node}

        while(!pq.empty()){
            auto[d, node]= pq.top(); pq.pop();
            if(d> dist[node])continue;
            for(int i=0; i<adj[node].size(); i++){
                int nbr=adj[node][i].first;
                int wt= adj[node][i].second;
                if( dist[node]+ wt < dist[nbr]){
                    dist[nbr]= dist[node]+ wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        //sabse door wla node
        int maxDist=0;
        for(int i=1; i<=n; i++){
            if(dist[i]==INT_MAX)return -1; //koi node unreachable
            maxDist=max(maxDist, dist[i]);
        }
            return maxDist;
    }
};