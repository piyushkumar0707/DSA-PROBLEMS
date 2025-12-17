class Solution {
private:
    // The "Worker": Visits all cities in one province
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;
        
        // Traverse the adjacency matrix row for the current node
        for (int neighbour = 0; neighbour < isConnected.size(); neighbour++) {
            // Check if there is a connection (1) and if we haven't visited it yet
            if (isConnected[node][neighbour] == 1 && !visited[neighbour]) {
                dfs(neighbour, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;

        // The "Manager": Checks for disconnected provinces
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // If we find an unvisited city, it's a new province
                provinces++; 
                dfs(i, isConnected, visited); // Visit the entire province
            }
        }
        
        return provinces;
    }
};