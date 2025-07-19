class Solution {
public:
bool possible(vector<int> &arr,int day,int m, int k){
    int cnt=0;
    int noofB=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            cnt++;
            if(cnt==k){
                noofB++;
                cnt=0;
            }
        }else{
            cnt=0;
        }
    }
    return noofB>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val= m*1LL*k*1LL;
        int ans=0;
        if(val>bloomDay.size())return -1;
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }return ans;

    }
};