class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n= monsters.size();

        vector<long long>bonus(n+1, 0);
        for(auto &b: boosts){
            bonus[b[0]]+=b[2];
            bonus[b[1]+1]-=b[2];
            
        }for(int i=1; i<n; i++){
            bonus[i]+=bonus[i-1];
        }
        auto ok= [&](long long s){
            for(int i=0; i<n; i++){
                if(s+bonus[i]<monsters[i])return false;
                s=max(0LL, s-monsters[i]);
            }return true;
        };
        long long lo=0, hi=0;
        for(int m:monsters)hi+=m;
        while(lo<hi){
            long long mid= lo+(hi-lo)/2;
            ok(mid)?hi=mid: lo=mid+1;
        }return lo;
    }
};