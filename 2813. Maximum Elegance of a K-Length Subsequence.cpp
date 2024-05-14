class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& a, int k) {
        sort(a.rbegin(), a.rend());
        long long ans = 0, cat = 0, cur = 0;
        vector<int> add(a.size() + 1);
        vector<int> dup;
        for (int i=0; i<k; ++i) {
            if (!add[a[i][1]]) {
                ++cat;
                add[a[i][1]] = true;
            } else
                dup.push_back(a[i][0]);
            cur += a[i][0];
        }
        cur += cat * cat;
        ans = cur;
        for (int i=k; i<a.size() && !dup.empty(); ++i) {
            if (add[a[i][1]]) continue;
            long long rmv = dup.back();
            dup.pop_back();
            cur = cur - rmv - cat*cat + a[i][0] + (cat+1)*(cat+1);
            ans = max(ans, cur);
            ++cat;
            add[a[i][1]] = true;
        }
        return ans;
    }
};