class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // adjacency list
        vector<int> indegree(numCourses, 0); // count of prerequisites

        // Build graph
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]); // edge from p[1] to p[0]
            indegree[p[0]]++;          // p[0] has one more prerequisite
        }

        queue<int> q;
        // Start with courses that have no prerequisites
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        int visited = 0;
        while (!q.empty()) {
            int course = q.front(); q.pop();
            visited++;

            for (int neighbor : adj[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return visited == numCourses; // If we visited all courses, it's possible
    }
};