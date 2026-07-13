class Solution {
public:

    void dfs(vector<vector<int>> & isConnected, vector<bool>& visited, int node){
        int n= isConnected.size();
        if(visited[node])return;
        visited[node]=true;

        for(int j=0; j<n; j++){
            if(!visited[j] && isConnected[node][j]==1){
                dfs(isConnected, visited, j);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n ,false);
        int count=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count ++;
                dfs(isConnected, visited, i);
            }

        }return count;

        
    }
};