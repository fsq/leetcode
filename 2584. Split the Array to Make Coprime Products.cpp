class Solution {
public:
    vector<int> p;

    int findValidSplit(vector<int>& nums) {
        vector<int> vis(1001, true);
        for (long long x=2; x<=1000; ++x)
            if (vis[x]) {
                for (long long i=x*x; i<=1000; i+=x) vis[i] = false;
                p.push_back(x);
            }

        map<int, int> m;
        unordered_map<int, vector<int>> a;
        for (int i=0; i<nums.size(); ++i) {
            int x = nums[i];
            if (x == 1) {
                ++m[i];
                --m[i];
                continue;
            }
            for (int j=0; j<p.size() && p[j]*p[j]<=x; ++j)
                if (x % p[j] == 0) {
                    if (a[p[j]].empty()) {
                        a[p[j]] = {i, i};
                    } else {
                        a[p[j]][1] = i;
                    } 
                    while (x % p[j] == 0) x /= p[j];
                }
            if (x != 1)
                if (a[x].empty()) {
                    a[x] = {i, i};
                } else {
                    a[x][1] = i;
                }
        }
        for (auto& s : a) {
            ++m[s.second[0]];
            --m[s.second[1]];
        }
        int ans = -1, cur = 0;
        for (auto& pr : m) {
            cur += pr.second;
            if (pr.first!=nums.size()-1 && cur==0) {
                ans = pr.first;
                break;
            }
        }
        return ans;
    }
};