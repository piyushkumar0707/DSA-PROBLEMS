class Solution {
public:
    int trailingZeroes(int n) {
        
        int power=5;
        int count=0;
        while(power<=n){
            count+=n/power;
            power=power*5;
        }return count;

    }
};