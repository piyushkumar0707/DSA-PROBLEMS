class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //step 1 freq count
        int freq[26]={0};
        for(char c: tasks){
            freq[c-'A']++;
        }

        //step-2 max freq
        int max_freq=*max_element(freq, freq+26);

        //step-3 kitne taks ki freq==max_freq hai
        int count_max=0;
        for(int i=0; i<26; i++){
            if(freq[i]==max_freq)count_max++;
        }
        int formula= (max_freq-1)*(n+1)+count_max;
        return max(formula,(int)tasks.size());
    }
};