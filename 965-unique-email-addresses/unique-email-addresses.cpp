class Solution {
public:
string normalizeEmail(const string& email) {
    string normalized;
    bool ignore = false;
    bool domain = false;
    
    for (char c : email) {
        if (c == '@') {
            domain = true;
            ignore = false;
        }
        
        if (!domain) {
            if (c == '+') {
                ignore = true;
            }
            if (c == '.') {
                continue;
            }
            if (ignore) {
                continue;
            }
        }
        
        normalized += c;
    }
    
    return normalized;
}
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
    
    for (const string& email : emails) {
        uniqueEmails.insert(normalizeEmail(email));
    }
    
    return uniqueEmails.size();
    }
};