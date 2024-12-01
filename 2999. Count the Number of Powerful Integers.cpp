class Solution {
public:
    long long ans = 0;
    int limit = 0;

    long long dfs(int i, string& num, string& sf, bool is_bound) {
        if (i + sf.size() >= num.size()) {
            if (is_bound) {
                return stoll(num) >= stoll(num.substr(0, max<int>(0, num.size()-sf.size()))+sf);
            } else {
                return 1;
            }
        }
        long long ans = 0;
        long long nxt = dfs(i+1, num, sf, false);
        if (is_bound) {
            int mx = min(limit, num[i]-'0');
            ans += mx * nxt;
            if (mx == num[i]-'0') {
                ans += dfs(i+1, num, sf, true);
            } else {
                ans += nxt;
            }
        } else {
            ans += (limit+1) * nxt;
        }
        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int lim, string s) {
        limit = lim;
        string mn = to_string(start-1);
        string mx = to_string(finish);
        auto ans1 = dfs(0, mx, s, true);
        auto ans2 = dfs(0, mn, s, true);
        return ans1 - ans2;
    }
};