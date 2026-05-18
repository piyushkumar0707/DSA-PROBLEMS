class Solution {
public:
    int reverse(int x) {
        long long num  = 0;
        while (x!=0){
            int  digit = x%10 ;
             num = num*10 + digit ; 
             if ( num<INT_MIN || num>INT_MAX) return 0 ;
             x = x/10 ;  
        }
        return (int)num ;
    }

};