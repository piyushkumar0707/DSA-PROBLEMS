class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        
        vector<pair<int, int>>sortedQ;
        for(int i=0; i<queries.size(); i++){
            sortedQ.push_back({queries[i],i});         
        }
        sort(sortedQ.begin(), sortedQ.end());
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int, int>>>pq;
        int i=0;

        vector<int> result(queries.size(),-1);
        for(auto& [q,idx]: sortedQ ){
            while(i<intervals.size() && intervals[i][0] <=q){
                int size= intervals[i][1]- intervals[i][0] +1;
                int end= intervals[i][1];
                pq.push({size,end});
                i++;
            }
                while(!pq.empty() && pq.top().second<q){
                    pq.pop();
                }

            if(!pq.empty()){
                result[idx]=pq.top().first;
            }
        }
        
            return result;

    }
};