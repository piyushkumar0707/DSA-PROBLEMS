class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=*max_element(weights.begin(),weights.end());
        int hi= accumulate(weights.begin(), weights.end(),0);
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(canship(weights, mid, days))hi=mid;
            else lo=mid+1;

        }return lo;
        
    }

    int canship(vector<int> &weights, int capacity, int days){
        int count=1, current=0;
        for(int weight: weights){
            if((weight + current) >capacity ){
                count++;
                current=0;
            }current+=weight;
        
        }return count<=days;

    }
};