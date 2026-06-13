class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>pairs;
        sort(potions.begin(), potions.end());
        for(int i=0; i<spells.size(); i++){
            int lo=0, hi=potions.size();
            while(lo<hi){
                int mid= lo+(hi-lo)/2;
                if((long long)spells[i]*potions[mid]>=success)hi=mid;
                else lo=mid+1;
            }pairs.push_back(potions.size()-lo);
        }return pairs;
    }
};