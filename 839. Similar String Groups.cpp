class Solution {
public:    
    vector<int> fa;
   
    bool similar(const string& a, const string& b) {
        vector<int> df;
        for (int i=0; i<a.size(); ++i)
            if (a[i]!=b[i]) {
                df.push_back(i);
                if (df.size()>2) return false;
            }
        if (df.size()==1) return false;
        if (df.size()==0) return true;
        return a[df[0]]==b[df[1]] && a[df[1]]==b[df[0]];
    }
    
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    
    int numSimilarGroups(vector<string>& a) {
        int n = a.size(), l = a[0].size();
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        
        if (n*n*l < n*l*l) {
            int d = n;
            for (int i=0; i<n; ++i)
                for (int j=i+1; j<n; ++j)
                    if (find(i) != find(j) && similar(a[i], a[j])) {
                        fa[fa[i]] = fa[j];
                        --d;
                    }
            return d;
        } else {
            unordered_map<string, int> m;
            for (int i=0; i<n; ++i) { 
                if (m.count(a[i])) fa[find(m[a[i]])] = -1;
                m[a[i]] = i;
            }

            for (int i=0; i<n; ++i)
                if (fa[i]!=-1)
                    for (int p=0; p<a[i].size(); ++p)
                        for (int q=p+1; q<a[i].size(); ++q)
                            if (a[i][p] != a[i][q]) {
                                string t = a[i];
                                swap(t[p], t[q]);
                                if (m.count(t)) {
                                    int j = m[t];
                                    if (find(i) != find(j)) fa[fa[i]] = fa[j];
                                }
                            }


            int ans = 0;
            for (int i=0; i<n; ++i) if (fa[i]==i) ++ans;
            return ans;
        }
    }
};