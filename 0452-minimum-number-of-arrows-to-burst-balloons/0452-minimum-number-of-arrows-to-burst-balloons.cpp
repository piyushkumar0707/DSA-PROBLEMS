class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        int arrow=1;
        int arrow_pos=points[0][1];
        for(int i=0; i<points.size(); i++){
            if(arrow_pos<points[i][0]){
                arrow++;
                arrow_pos=points[i][1];
            }
        }return arrow;
    }
};