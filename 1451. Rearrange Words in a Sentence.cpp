class Solution {
public:
    string arrangeWords(string text) {
        vector<string> wd;
        istringstream is(text);
        string word;
        while (is >> word) {
            wd.push_back(word);
        }
        wd[0][0] = tolower(wd[0][0]);
        stable_sort(wd.begin(), wd.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        string ans;
        wd[0][0] = toupper(wd[0][0]);
        for (auto s : wd)
            if (ans.empty())
                ans = s;
            else 
                ans += ' ' + s;
        return ans;
            
    }
};