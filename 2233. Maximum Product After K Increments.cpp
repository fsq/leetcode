class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto x : nums) ++m[x];
        for (auto it=m.begin(); k>0 && it!=m.end(); ++it) {
            auto nxt = next(it);
            int cnt = it->second, x = it->first;
            int nx = nxt==m.end() ? 0 : nxt->first;
            if (nxt != m.end() && k >= (nx-x) * cnt) {
                it->second = 0;
                nxt->second += cnt;
                k -= (nx-x) * cnt;
            } else if (k >= cnt) {
                it->second = 0;
                m[x + k/cnt] += cnt - k%cnt;
                m[x + k/cnt + 1] += k%cnt;
                k = 0;
            } else {
                m[x+1] += k;
                it->second -= k;
                k = 0;
            }
        }
        long long ans = 1;
        for (auto& pr : m)
            for (int i=0; i<pr.second; ++i)
                ans = (ans * pr.first) % 1000000007;
        return ans;
    }
};