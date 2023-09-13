class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> ma;
        map<int, int> cnt;
        int mn = INT_MAX;
        for (auto x : a) {
            ++cnt[x];
            ++ma[x];
            mn = min(mn, x);
        }
        for (auto x : b) {
            ++cnt[x];
            mn = min(mn, x);
        }
        for (auto pr : cnt)
            if (pr.second & 1)
                return -1;
        
        int miss = 0;
        vector<int> sa, sb;
        for (auto pr : cnt) {
            int x = pr.first, cnt = pr.second;
            if (ma[x] > cnt/2) {
                sa.insert(sa.end(), ma[x]-cnt/2, x);
            } else if (ma[x] < cnt/2) {
                sb.insert(sb.end(), cnt/2-ma[x], x);
            }
        }
        long long ans = 0;
        for (int i=0; i<sa.size(); ++i) {
            ans += min(mn*2, min(sa[i], sb[sb.size()-i-1]));
        }
        return ans;
    }
};