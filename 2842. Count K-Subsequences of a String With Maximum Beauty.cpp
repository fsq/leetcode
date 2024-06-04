class Solution {
public:
    vector<int> cnt;
    unordered_map<int, long long> m;
    int mx = 0;
    int mx_cnt = 0;
    const int M = 1000000007;

    void dfs(int i, int rm, int sm, long long ways) {
        if (rm == 0) {
            m[sm] = (m[sm] + ways) % M;
            mx = max(mx, sm);
            return;
        }
        if (i >= cnt.size()) return;
        if (cnt.size()-i-1 >= rm) dfs(i+1, rm, sm, ways);
        if (rm*mx_cnt+sm >= mx) {
            dfs(i+1, rm-1, sm+cnt[i], ways*cnt[i]%M);
        }
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        unordered_map<int, int> letter;
        for (auto c : s) ++letter[c - 'a'];
        for (auto& pr : letter)
            cnt.push_back(pr.second);

        mx_cnt = *max_element(cnt.begin(), cnt.end());

        dfs(0, k, 0, 1ll);

        return m[mx] % M;
    }
};