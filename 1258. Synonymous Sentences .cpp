class Solution {
public:
    unordered_map<string, string> fa;
    unordered_map<string, vector<string>> g;
    vector<string> ans;
    
    string find(const string& s) {
        if (!fa.count(s)) 
            return fa[s] = s;
        else 
            return fa[s]==s ? s : fa[s]=find(fa[s]);
    }
    
    void dfs(const vector<string>& s, vector<string>& a, int i) {
        if (i == s.size()) {
            string w = a[0];
            for (int i=1; i<a.size(); ++i) w += " " + a[i];
            ans.push_back(move(w));
        } else {
            for (auto& w : g[find(s[i])]) {
                a.push_back(w);
                dfs(s, a, i+1);
                a.pop_back();
            }
        }
    }
    
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        for (auto& pr : synonyms) {
            string fx=find(pr[0]), fy=find(pr[1]);
            if (fx != fy) 
                fa[fx] = fy;
        }    
        for (auto &pr : fa)
            g[find(pr.second)].push_back(pr.first);
        
        istringstream sin(text);
        vector<string> s;
        string w;
        while (getline(sin, w, ' ')) {
            s.push_back(w);
            if (!fa.count(w)) {
                fa[w] = w;
                g[w].push_back(w);
            }
        }
        
        for (auto &pr : g) sort(pr.second.begin(), pr.second.end());
        
        vector<string> now;
        dfs(s, now, 0);
        return ans;
    }
};