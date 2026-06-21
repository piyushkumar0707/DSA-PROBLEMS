class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>st;
        int currentNum=0;
        string currentString="";

        for(char c:s){
            if(isdigit(c)){
                currentNum=currentNum*10+(c-'0');
            }
            else if(c=='['){
                st.push({currentString, currentNum});
                currentNum=0;
                currentString="";

            }else if(c==']'){
                auto top= st.top(); st.pop();
                string prevString= top.first;
                int num= top.second;

                string temp="";
                for(int i=0; i<num; i++){
                    temp+=currentString;
                }currentString= prevString+temp;
            }else{
                currentString+=c;
            }
        }return currentString;
    }
};