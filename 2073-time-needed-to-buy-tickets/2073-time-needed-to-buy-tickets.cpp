class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        int n=tickets.size();
        for(int i=0; i<n; i++){
            if(i<=k){
                time+= min(tickets[i],tickets[k]);
            }else{
                time+=min(tickets[i], tickets[k]-1);
            }
        }return time;
    }
};