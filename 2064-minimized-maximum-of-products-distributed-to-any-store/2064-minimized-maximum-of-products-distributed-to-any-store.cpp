class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo=1, hi=*max_element(quantities.begin(),quantities.end());
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(check(quantities, mid,n))hi=mid;
            else lo=mid+1;
        }return lo;
        
    }

    int check(vector<int>& quantities, int mid, int n){
        int stores=0;
        for(int quantity: quantities){
            stores+= (quantity+mid-1)/mid ;
        }return stores<=n;

    }
};