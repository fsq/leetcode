class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size()<(1<<k)+k-1) return false;
        int now = 0;
        for (int i=0; i<k; ++i)
            now |= (s[i]-'0') << i;
        vector<int> vis(1<<k);
        vis[now] = true;
        for (int i=k; i<s.size(); ++i) {
            now >>= 1;
            now |= (s[i]-'0') << (k-1);
            vis[now] = true;
        }
        return all_of(vis.begin(), vis.end(), [](int x) {
            return x==1;
        });
    }
};