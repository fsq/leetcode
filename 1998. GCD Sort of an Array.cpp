class Solution {
public:
    
    vector<int> p;
    unordered_map<int, int> fa;
    
    int find(int x) {
        if (fa[x]==0) return fa[x]=x;
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    
    bool gcdSort(vector<int>& a) {
        int mx = *max_element(a.begin(), a.end());
        for (int i=2; i<=mx; ++i) {
            bool ok = true;
            for (int j=2; j*j<=i; ++j)
                if (i % j == 0) {
                    ok = false;
                    break;
                }
            if (ok) p.push_back(i);
        }
        
        vector<int> first_p;
        for (auto x : a) {
            vector<int> pf;
            for (auto y : p) {
                if (x % y == 0) {
                    pf.push_back(y);
                    while (x>1 && x%y==0) x/=y;
                }
                if (x == 1) break;
            }
            first_p.push_back(pf[0]);
            for (int i=1; i<pf.size(); ++i) {
                int f1 = find(pf[0]), f2 = find(pf[i]);
                fa[f2] = f1;
            }
        }
        
        unordered_map<int, vector<int>> gs;
        for (int i=0; i<a.size(); ++i)
            gs[find(first_p[i])].push_back(i);
        
        if (gs.size() == 1) return true;
        auto sorted = a;
        sort(sorted.begin(), sorted.end());
        for (auto& g : gs) {
            unordered_set<int> st;
            for (auto i : g.second) st.insert(sorted[i]);
            for (auto i : g.second) 
                if (!st.count(a[i]))
                    return false;
        }
        return true;
    }
};