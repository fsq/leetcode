class Solution {
public:
    
    vector<int> tp(vector<int>& a, vector<pair<int,int>>& p) {
        unordered_map<int, vector<int>> e;
        unordered_map<int, int> ind;
        for (auto& pr: p) {
            e[pr.first].push_back(pr.second);
            ++ind[pr.second];
        }
        queue<int> q;
        vector<int> ans;
        for (auto x : a)
            if (!ind.count(x))
                q.push(x);
        
        while (!q.empty()) {
            int x = q.front(); q.pop();
            ans.push_back(x);
            for (auto y : e[x])
                if (--ind[y]==0)
                    q.push(y);
        }
        
        return ans;
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i=0; i<n; ++i) 
            if (group[i]==-1) 
                group[i] = m++;
        vector<vector<int>> elem(m), rg(m);
        vector<int> indg(m);
        vector<vector<pair<int,int>>> ring(m);
        
        for (int i=0; i<n; ++i) {
            elem[group[i]].push_back(i);
            for (auto y : beforeItems[i]) {
                if (group[i] == group[y]) 
                    ring[group[i]].push_back({y, i});
                else {
                    rg[group[y]].push_back(group[i]);
                    ++indg[group[i]];
                }
            }
        }
          
        vector<vector<int>> seg;
        for (int i=0; i<m; ++i) {
            auto s = tp(elem[i], ring[i]);
            if (s.size() != elem[i].size()) return {};
            seg.push_back(s);
        }
        
        queue<int> q;
        for (int i=0; i<m; ++i) 
            if (indg[i]==0) 
                q.push(i);
        
        vector<int> seq;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            seq.push_back(x);
            for (auto y : rg[x])
                if (--indg[y]==0)
                    q.push(y);
        }
        
        if (seq.size() != m) return {};
        
        vector<int> ans;
        for (auto x : seq)
            ans.insert(ans.end(), seg[x].begin(), seg[x].end());
        return ans;
    }
};