class Solution {
public:
    string removeKdigits(string num, int k) {
        string st=""; //stack
        for(int i=0; i<num.size(); i++){
            char digit= num[i];

         // jab tak k>0 AND stack empty nahi AND top > current digit
            while(k>0 && !st.empty() && st.back()> digit){
                st.pop_back();
                k--;
            }

                st.push_back(digit);
        // agar k abhi bhi bacha hai — end se hatao
        }while(k>0){
            st.pop_back();
            k--;
        }


    // leading zeros hatao
        int i=0;
        while(i<st.size() && st[i]=='0'){
            i++;
        }st= st.substr(i);

         // agar empty ho gaya
        if(st.empty())return "0";
        return st;
    }
};