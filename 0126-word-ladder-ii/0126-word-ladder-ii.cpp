class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};

        unordered_map<string, vector<string>> graph;
        unordered_set<string> beginSet{beginWord}, endSet{endWord};
        bool found = false, reversed = false;

        while (!beginSet.empty() && !endSet.empty() && !found) {
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
                reversed = !reversed;
            }

            unordered_set<string> nextLevel;
            for (const string& word : beginSet) wordSet.erase(word);

            for (const string& word : beginSet) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (!wordSet.count(temp)) continue;

                        if (endSet.count(temp)) found = true;
                        nextLevel.insert(temp);

                        string from = reversed ? temp : word;
                        string to = reversed ? word : temp;
                        graph[from].push_back(to);
                    }
                    temp[i] = original;
                }
            }
            swap(beginSet, nextLevel);
        }

        vector<vector<string>> results;
        if (found) {
            vector<string> path{beginWord};
            dfs(beginWord, endWord, graph, path, results);
        }
        return results;
    }

private:
    void dfs(const string& word, const string& endWord,
             unordered_map<string, vector<string>>& graph,
             vector<string>& path, vector<vector<string>>& results) {
        if (word == endWord) {
            results.push_back(path);
            return;
        }

        for (const string& next : graph[word]) {
            path.push_back(next);
            dfs(next, endWord, graph, path, results);
            path.pop_back();
        }
    }
};