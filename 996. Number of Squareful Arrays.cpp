class Solution {
public:
    int ans = 0, n = 0;
    
    bool sqr(int x) {
        int y = sqrt(x);
        return y*y == x;
    }
    
    void dfs(unordered_map<int, int>& a, int pre, int i) {
        if (i==n)
            ++ans;
        else {
            for (auto it=a.begin(); it!=a.end(); ++it)
                if (it->second && (pre==-1 || sqr(it->first+pre))) {
                    --it->second;
                    dfs(a, it->first, i+1);
                    ++it->second;
                }
        }
    }
    
    int numSquarefulPerms(vector<int>& _a) {
        n = _a.size();
        unordered_map<int, int> a;
        for (auto x : _a) ++a[x];
        
        dfs(a, -1, 0);
        return ans;
    }
};