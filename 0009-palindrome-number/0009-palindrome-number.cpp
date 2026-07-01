class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long original=x;
      long long reversed=0;
        
         long long n=x;
        while(n>0){
            int digit=n%10;
            reversed=reversed*10+digit;
            n/=10;
        }
        return reversed==original;
        
    }
};