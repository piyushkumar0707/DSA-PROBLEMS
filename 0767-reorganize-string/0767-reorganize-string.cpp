class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>freq;
        for(char c: s)freq[c]++;

        priority_queue<pair<int, char>> maxHeap;
        for(auto& [ch, f]: freq){
            maxHeap.push({f,ch});
        }
        string result="";
        pair<int, char> prev={0, '#'};

        while(!maxHeap.empty()){
            auto curr=maxHeap.top();
            maxHeap.pop();

            result+=curr.second; //result me first char store karliya 
            curr.first--;  //first char ki freq ghatao

            if(prev.first>0){  //prev wale ko wapis push karo agar uski freq >0 hai aur usko hold karo 
                maxHeap.push(prev);
            }
            prev=curr;

        }if(result.size()!=s.size())return "";
        return result;
        
    }
};