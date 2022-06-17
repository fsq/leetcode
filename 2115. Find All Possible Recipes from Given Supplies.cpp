class Solution {
public:
    vector<string> findAllRecipes(vector<string>& re, vector<vector<string>>& ing, vector<string>& supl) {
        unordered_map<string, vector<string>> e;
        unordered_set<string> sup(supl.begin(), supl.end());
        unordered_map<string, int> ind;
        for (int i=0; i<re.size(); ++i) {
            for (auto& pre : ing[i]) {
                e[pre].push_back(re[i]);
                ++ind[re[i]];
            }
        }
        vector<string> ans;
        queue<string> q;
        for (auto& s : supl) q.push(s);
        while (q.size()) {
            auto now = q.front(); q.pop();
            if (!sup.count(now)) ans.push_back(now);
            for (auto& nxt : e[now])
                if (--ind[nxt] == 0) {
                    q.push(nxt);
                }
        }
        return ans;
    }
};