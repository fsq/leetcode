class Solution {
public:
    int bs = 0;
    vector<int> vis;
    
    bool dfs(vector<int>& a, vector<int>& b, int i) {
        if (i==a.size()) return true;
        for (int j=0; j<4; ++j)
            if (b[j]+a[i] <= bs) {
                bool same = false;
                for (int k=0; k<j; ++k) 
                    if (b[k]==b[j]) {
                        same = true;
                        break;
                    }
                if (same) continue;
                b[j] += a[i];
                if (dfs(a, b, i+1)) return true;
                b[j] -= a[i];
            }
        return false;
    }
    
    bool makesquare(vector<int>& a) {
        if (a.size()<4) return false;
        int s = accumulate(a.begin(), a.end(), 0);
        if (s%4) return false;
        bs = s / 4;
        vis.resize(a.size());        
        sort(a.begin(), a.end(), std::greater<int>());
        if (a[0]>bs) return false;
        while (a.size() && a.back()==0) a.pop_back();
        if (a.empty()) return false;
        
        vector<int> bin(4);
        return dfs(a, bin, 0);
    }
};