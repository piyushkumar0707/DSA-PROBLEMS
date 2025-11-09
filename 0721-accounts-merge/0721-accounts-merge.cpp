class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;
        unordered_map<string, string> emailToName;

        // Step 1: Initialize parent and map email to name
        for (const auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                parent[account[i]] = account[i]; // each email is its own parent initially
                emailToName[account[i]] = name;
            }
        }

        // Step 2: Union emails in the same account
        for (const auto& account : accounts) {
            string rootEmail = find(account[1], parent);
            for (int i = 2; i < account.size(); ++i) {
                string currentEmail = find(account[i], parent);
                parent[currentEmail] = rootEmail;
            }
        }

        // Step 3: Group emails by root parent
        unordered_map<string, set<string>> unions;
        for (const auto& [email, _] : parent) {
            string root = find(email, parent);
            unions[root].insert(email);
        }

        // Step 4: Format result
        vector<vector<string>> result;
        for (const auto& [root, emails] : unions) {
            vector<string> mergedAccount;
            mergedAccount.push_back(emailToName[root]);
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());
            result.push_back(mergedAccount);
        }

        return result;
    }

private:
    string find(string email, unordered_map<string, string>& parent) {
        if (parent[email] != email)
            parent[email] = find(parent[email], parent); // path compression
        return parent[email];
    }
};