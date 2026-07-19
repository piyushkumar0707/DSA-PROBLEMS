class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0; i<points.size(); i++){
            int dist= points[i][0] * points[i][0]+ (points[i][1] * points[i][1]);
            pq.push({dist, i});
        }

        vector<vector<int>>result;
        while(k--){
            int idx= pq.top().second;
            pq.pop();
            result.push_back(points[idx]);

        }
        return result;

        
    }
};