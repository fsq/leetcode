class Solution {
public:
    int maximumSetSize(vector<int>& a, vector<int>& b) {
        unordered_set<int> s1(a.begin(), a.end()), s2(b.begin(), b.end());
        int ua=0, ub=0;
        for (auto x : s1) if (!s2.count(x)) ++ua;
        for (auto x : s2) if (!s1.count(x)) ++ub;
        int ans = 0;
        ans += min<int>(ua, a.size()/2); // pick unique in a
        ans += min<int>(ub, b.size()/2); // pick unique in b
        ans += s1.size()-ua; // fill rest with common elements
        ans = min<int>(ans, a.size());
        return ans;
    }
};