class Solution {
public:
    int n;
    const int m = 1000000007;
    vector<int> pd;
    
    long long prod(int x) {
        if (pd[x] != 0) return pd[x];
        if (x==0) return 1;
        return pd[x] = prod(x-1) * x % m;
    }
    
    long long pow(int x, int y) {
        if (y==0) return 1;
        if (y==1) return x;
        long long s = pow(x, y/2);
        long long ans = s * s % m;
        if (y & 1) ans = (ans * x) % m;
        return ans;
    }
    
    vector<long long> dfs(vector<vector<int>>& e, int x) {
        long long ans = 1, tot = 0;
        vector<int> s;
        for (auto y : e[x]) {
            auto pr = dfs(e, y);
            ans = (ans * pr[0]) % m;
            s.push_back(pr[1]);
            tot += s.back();
        }
        ans = (ans * prod(tot)) % m;
        for (int i=0; i<s.size(); ++i) {
            ans = (ans * pow(prod(s[i]), m-2)) % m;
        }
        ++tot;
        return {ans, tot};
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) {
        n = prevRoom.size();
        pd.resize(n+1);
            
        vector<vector<int>> e(n, vector<int>());
        for (int i=1; i<n; ++i)
            e[prevRoom[i]].push_back(i);
        return dfs(e, 0)[0];
    }
};