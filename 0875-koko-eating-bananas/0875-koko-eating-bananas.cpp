class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1, hi=*max_element(piles.begin(),piles.end());
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(check(piles, mid, h))hi=mid;
            else lo=mid+1;
        }return lo;
        
    }

    bool check(vector<int> &piles, int k, int h){ //to find feasibilty
        int hours=0;
        for(int i=0; i<piles.size();i++){
            hours+= (piles[i]-1+k)/k;
        }return hours<=h;
    }
};