class Solution {
public:


    int count=0;
    void expandAroundCenter(string &s, int left, int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            count++;
            left--; right++;
        }

    }




    int countSubstrings(string s) {
        int n=s.size();
        for(int i=0; i<n; i++){
            expandAroundCenter(s,i,i);// odd length
            expandAroundCenter(s,i,i+1); //even length 2 center i, i+1

        }return count;
        
    }
};