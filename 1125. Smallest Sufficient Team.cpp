class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& b, vector<vector<string>>& p) {
        unordered_map<string, int> ind;
        for (int i=0; i<b.size(); ++i)
            ind[b[i]] = i;

        vector<int> a;
        for (int i=0; i<p.size(); ++i) {
            int s = 0;
            for (auto& c : p[i])
                s |= 1 << ind[c];
            a.push_back(s);
        }
        
        vector<vector<int>> f(1<<b.size());
        for (int i=0; i<(1<<b.size()); ++i) 
            if (i==0 || f[i].size()) 
                for (int j=0; j<a.size(); ++j)
                    if ((i | a[j]) > i && 
                        (f[i|a[j]].empty() || f[i|a[j]].size()>f[i].size()+1)) {
                        f[i|a[j]] = f[i];
                        f[i|a[j]].push_back(j);
                    }
        
        
        return f.back();
    }
};