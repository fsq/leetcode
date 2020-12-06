class Solution {
public:
    int minMoves(vector<int>& a, int limit) {
        vector<int> s(2*limit + 2);
        for (int i=0; i<a.size()/2; ++i) {
            int j = a.size() - i - 1;
            s[2] += 2;
            --s[min(a[i], a[j]) + 1];
            --s[a[i] + a[j]];
            ++s[a[i] + a[j] + 1];
            ++s[max(a[i], a[j]) + limit + 1];
        }
        int cur = 0, ans = a.size();
        for (int i=2; i<s.size(); ++i) {
            cur += s[i];
            ans = min(ans, cur);
        }
        return ans;
    }
};