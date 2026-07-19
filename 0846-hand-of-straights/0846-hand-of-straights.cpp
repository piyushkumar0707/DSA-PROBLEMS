class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() %groupSize !=0)return false;
        map<int, int>freq;
        for(int card: hand){
            freq[card]++;
        }
        while(!freq.empty()){
            int smallest= freq.begin()->first; // sabse chota card

            for(int i=0; i<groupSize; i++){
                int card= smallest + i;

                if(freq.find(card)==freq.end())return false; // card missing hai — invalid group

                freq[card]--;
                if(freq[card]==0){
                    freq.erase(card);
                }
            }
        }return true;
        
    }
};