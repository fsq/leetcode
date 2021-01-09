class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> m;
        for (int i=0; i<a.size(); ++i) m[a[i]] = i;
        for (auto& x : b)
            x = m.count(x) ? m[x] : -1;

        vector<int> s;
        for (auto x : b)
            if (x != -1) {
                int i = lower_bound(s.begin(), s.end(), x) - s.begin();
                if (i == s.size()) {
                    s.push_back(x);
                } else {
                    s[i] = x;
                }
            }

        return a.size() - s.size();
    }
};