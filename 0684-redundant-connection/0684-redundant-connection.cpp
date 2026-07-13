class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int> parent(n+1);

        for(int i=0; i<=n; i++)parent[i]=i; //har node apne khud ka parent
        for(int i=0; i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            int pu= find(parent, u);
            int pv= find(parent, v);

            if(pu==pv)return edges[i]; //cycle ban rhi yehi redundant edge hao
            parent[pu]=pv; //unite karo

        }return {};
    }

    int find(vector<int>& parent, int x){
        if(parent[x]==x)return x;
        return find(parent, parent[x]);
    }
};