class Solution {
public:

    unordered_map<string, vector<string>>adj;
    unordered_map<string, bool>visited;
    void dfs(string email, vector<string>& component){
        if(visited[email])return;
        visited[email]=true;
        component.push_back(email);

        for(int i=0; i<adj[email].size(); i++){
            if(!visited[adj[email][i]])dfs(adj[email][i],component);
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //adjacency list bnao
        for(int i=0; i<accounts.size(); i++){
            string first= accounts[i][1];// pehla email representative
            for(int j=2; j<accounts[i].size(); j++){
                adj[first].push_back(accounts[i][j]);
                adj[accounts[i][j]].push_back(first);
            }

        }// step-2 email to name map banao
        unordered_map<string, string> emailToName;
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                emailToName[accounts[i][j]]=accounts[i][0];
            }
        }
        //step 3- dfs se connected components nikalo
        vector<vector<string>>result;
        for(int i=0; i<accounts.size(); i++){
            string first= accounts[i][1];
            if(!visited[first]){
                vector<string>component;
                dfs(first, component);
                sort(component.begin(), component.end()); //emails sort karo
                component.insert(component.begin(), emailToName[first]); //name pehle
                result.push_back(component);
            }
        }return result;

    }
};