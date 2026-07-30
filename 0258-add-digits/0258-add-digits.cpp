class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            int temp=num;
            int sum=0;
            while(temp>0){
                int digit=temp%10;
                sum+=digit;
                temp=temp/10;
            }num=sum;
        }return num;
    }
};