class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state){
        state[node]=1; //unvivisited hai
        for(int i=0; i<adj[node].size(); i++){
            int nbr= adj[node][i];
            if(state[nbr]==1)return true;
            if(state[nbr]==0 && dfs(nbr, adj, state))return true;
        }
        state[node]=2;
        return false;

    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]); //directed graph
        }

        vector<int>state(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(state[i]==0){
                if(dfs(i, adj, state))return false;

            }
        }return true;
        
    }
};