class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // adjacency list
        vector<int> inDegree(numCourses, 0); // track incoming edges
        vector<int> order; // final course order

        // Build graph
        for (auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        // Queue for courses with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Process courses
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            order.push_back(curr);

            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If all courses are processed, return order
        if (order.size() == numCourses)
            return order;
        else
            return {}; // cycle detected
    }
};