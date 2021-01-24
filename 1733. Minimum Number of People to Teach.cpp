class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& language, vector<vector<int>>& f) {
        vector<unordered_set<int>> lan(language.size()+1);
        for (int i=0; i<language.size(); ++i)
            for (auto x : language[i])
                lan[i+1].insert(x);
        
        vector<int> match(f.size());
        for (int i=0; i<f.size(); ++i)
            for (auto xl : lan[f[i][0]])
                if (lan[f[i][1]].count(xl)) {
                    match[i] = true;
                    break;
                }
        
        int ans = language.size();
        for (int l=1; l<=n; ++l) {
            unordered_set<int> teach;
            for (int i=0; i<f.size(); ++i) {
                if (match[i]) continue;
                int x = f[i][0], y = f[i][1];
                if (!teach.count(x) && !lan[x].count(l)) {
                    teach.insert(x);
                }
                if (!teach.count(y) && !lan[y].count(l)) {
                    teach.insert(y);
                }
            }
            ans = min<int>(ans, teach.size());
        }
        return ans;
    }
};