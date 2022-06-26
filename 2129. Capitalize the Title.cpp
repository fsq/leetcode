class Solution {
public:
    string capitalizeTitle(string title) {
        istringstream sin(title);
        string ans, s;
        while (sin >> s) {
            for (auto& c : s) c = tolower(c);
            if (s.size() > 2) s[0] = toupper(s[0]);
            ans += s + ' ';
        }
        ans.pop_back();
        return ans;
    }
};