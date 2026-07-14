class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    
    // endWord list mein nahi hai
    if(wordSet.find(endWord) == wordSet.end()) return 0;
    
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    wordSet.erase(beginWord); // visited mark
    
    while(!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        // Har position pe a-z try karo
        for(int i = 0; i < word.size(); i++) {
            string temp = word;
            for(char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;
                if(temp == endWord) return steps + 1;
                if(wordSet.find(temp) != wordSet.end()) {
                    q.push({temp, steps + 1});
                    wordSet.erase(temp); // visited
                }
            }
        }
    }
    return 0;
}
};