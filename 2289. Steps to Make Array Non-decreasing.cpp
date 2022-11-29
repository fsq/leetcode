class Solution {
public:
    int totalSteps(vector<int>& a) {
        vector<int> s, p(a.size());
        for (int i=0; i<a.size(); ++i) {
            int mx = 0;
            while (s.size() && a[s.back()] <= a[i]) {
                mx = max(mx, p[s.back()]);
                s.pop_back();
            }
            if (s.size()) {
                p[i] = mx + 1;
            }
            s.push_back(i);
        }
        return *max_element(p.begin(), p.end());
    }
};