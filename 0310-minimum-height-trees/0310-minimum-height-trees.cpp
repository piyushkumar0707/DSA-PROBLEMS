class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // case 1 single node
        if(n==1)return {0};

        //step 1 ajacency list bnao
        vector<vector<int>> graph(n);
        vector<int>degree(n,0);
        for(auto& edge: edges){
            int a=edge[0], b=edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            degree[a]++;
            degree[b]++;

        }

        //step-2 saari leaves (degree==1)queue mein dalo
        queue<int>leaves;
        for(int i=0; i<n; i++){
            if(degree[i]==1){
                leaves.push(i);
            }
        }
        //step 3 oninon peeling
        int remaining=n;
        while(remaining>2){
            int leavesCount=leaves.size();
            remaining-=leavesCount;

            for(int i=0; i<leavesCount; i++){
                int leaf=leaves.front();
                leaves.pop();

                //is leaves ke neighbour ka degree htao
                for(int neighbour: graph[leaf]){
                    degree[neighbour]--;
                    if(degree[neighbour]==1){
                        leaves.push(neighbour);

                    }
                }
            }
        }
        //step 4 jo bacha hai whi answer hai
        vector<int>result;
        while(!leaves.empty()){
            result.push_back(leaves.front());
            leaves.pop();

        }
            return result;
        

    }
};