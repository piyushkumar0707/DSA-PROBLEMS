class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>result;
        int n= s.size();
        int start=0;
        for(int i=1; i<=n; i++){
            if(i==n || s[i]!=s[i-1]){
                int end= i-1;
                if(end-start+1>=3){
                    result.push_back({start,end});
                }start=i;

            }
        }return result;
    }
};