class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int lo=1, hi= x;
        while(lo<hi){
            long long mid= lo+(hi-lo+1)/2;//upper mid
            if(mid*mid<=x)lo=mid; //valid, go right
            else hi=mid-1; //invalid, go left
        }return lo;
        
    }
};