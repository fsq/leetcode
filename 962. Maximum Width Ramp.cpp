class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        vector<int> s;
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            if (s.empty() || a[i]<a[s.back()])
                s.push_back(i);
            else {
                int j = lower_bound(s.begin(), s.end(), a[i], [&](int i, int x) {
                    return a[i] > x;
                }) - s.begin();
                ans = max(ans, i-s[j]);
            }
        return ans;
    }
};