class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& vd, vector<vector<int>>& fr, int id, int lv) {
        int n = vd.size();
        vector<int> vis(n);
        vis[id] = true;
        unordered_map<string, int> f;
        queue<int> q;
        q.push(id);
        for (int d=0; d<lv; ++d) 
            for (int sz=q.size(); sz; sz--) {
                int x = q.front();
                q.pop();
                for (auto y : fr[x])
                    if (!vis[y]) {
                        vis[y] = true;
                        q.push(y);
                    }
            }
        while (q.size()) {
            auto x = q.front();
            for (auto& name : vd[x])
                ++f[name];        
            q.pop();
        }
        vector<string> ans;
        for (auto& pr : f) ans.push_back(pr.first);
        sort(ans.begin(), ans.end(), [&](string& a, string& b) {
            return f[a]<f[b] || f[a]==f[b] && a<b;
        });
        return ans;
    }
};