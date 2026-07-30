class Solution {
public:
    string decodeMessage(string key, string message) {
        char mapping[26];
        for(int i=0; i<26; i++)mapping[i]='\0';//sab unset
        char nextChar='a';

        //mapping bnao key se
        for(char c: key){
            if(c==' ')continue;
            if(mapping[c-'a']=='\0'){
                mapping[c-'a']= nextChar;
                nextChar++;

            }
        }//message decoding
        string result="";
        for(char c: message){
            if(c== ' '){
                result+=' ';

            }else{
                result+=mapping[c-'a'];
            }
        }
        return result;

    }
};