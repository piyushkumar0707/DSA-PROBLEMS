class Solution {
private:
    // STANDARD DFS HELPER (The Worker)
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
        visited[node] = 1; 
        for(auto neighbour : adj[node]) {
            if(!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        // STEP 1: Convert Matrix to Adjacency List
        // This makes the rest of the code standard for any problem
        vector<vector<int>> adj(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // STEP 2: Initialize Visited Array
        vector<int> visited(V, 0);
        int provinces = 0;

        // STEP 3: Loop for Disconnected Components (The Manager)
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                provinces++;          // Logic: Found a new province
                dfs(i, adj, visited); // Action: Visit all cities in this province
            }
        }
        return provinces;
    }
};