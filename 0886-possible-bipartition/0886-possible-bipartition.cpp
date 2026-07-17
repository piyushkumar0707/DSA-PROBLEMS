class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);

        for(auto& d: dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);

        }
        vector<int>color(n+1, -1);
        for(int i=1; i<=n; i++){
            if(color[i]!=-1)continue; //already visited;

        
        queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node= q.front(); q.pop();
            for(int neighbor: graph[node]){
                if(color[neighbor]==-1){
                    color[neighbor]=1-color[node];
                    q.push(neighbor);
                }else if(color[neighbor]==color[node]){
                    return false;
                }
            }
        }
        }return true;
    }
};