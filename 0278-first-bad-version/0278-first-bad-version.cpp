// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo=1, high=n;
        while(lo<high){
            int mid= lo+(high-lo)/2;
            if(isBadVersion(mid)==true)high=mid;
            else if(isBadVersion(mid)==false)lo=mid+1;
        }
        return lo;
    }
};