class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string>rows(numRows);
        int currentRows=0;
        int direction=-1;

       for(char c:s){
        rows[currentRows]+=c;

        if(currentRows==0 || currentRows==numRows-1){
            direction=-direction;
        }currentRows+=direction;
       }

       string result="";
       for(string row: rows){
        result+=row;
       } 
       return result;
    }
};