class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>result;
        int n= intervals.size(); 
        int i=0;

        //case 1 new se pehle khatam hone wala interval- as it is push
        while(i<n && intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        //case 2 jav overlapping ho
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]= min(intervals[i][0], newInterval[0]);
            newInterval[1]= max(intervals[i][1], newInterval[1]);
            i++;
        }result.push_back(newInterval);

        //case 3 jab new interval ke bad ho- as it is push

        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};