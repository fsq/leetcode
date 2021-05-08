class Solution {
public:
    
    vector<string> sep(const string& s) {
        istringstream sin(s);
        string w;
        vector<string> ans;
        while (sin >> w) {
            ans.push_back(w);
        }
        return ans;
    }
    
    bool areSentencesSimilar(string sa, string sb) {
        if (sa.size() < sb.size()) sa.swap(sb);
        auto a = sep(sa), b = sep(sb);
        int i = 0, j = 0;
        while (i<b.size() && a[i]==b[i]) ++i;
        while (j<b.size() && a[a.size()-j-1]==b[b.size()-j-1]) ++j;
        return i+j>=b.size();
    }
};