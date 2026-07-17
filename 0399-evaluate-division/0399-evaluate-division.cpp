class Solution {
public:


    unordered_map<string, vector<pair<string , double>>> adj;
    double dfs(string src, string dst, unordered_set<string>& visited){
        if(adj.find(src)==adj.end())return -1.0;
        if(src==dst)return 1.0;

        visited.insert(src);
        for(int i=0; i<adj[src].size(); i++){
            string nbr= adj[src][i].first;
            double wt= adj[src][i].second;

            if(visited.find(nbr)==visited.end()){
                double result= dfs(nbr,dst, visited);
                if(result!= -1.0)return wt* result;
            }
        }return -1.0;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        //step 1 make graph
        for(int i=0; i<equations.size(); i++){
            string a= equations[i][0], b= equations[i][1];
            double val= values[i];

            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0/val});
        }
        
        // step 2 har query ke liye dfs
        vector<double>result;
        for(int i=0; i<queries.size(); i++){
            string src=queries[i][0], dst= queries[i][1];
            unordered_set<string> visited;
            result.push_back(dfs(src, dst, visited));
        }return result;
    }
};