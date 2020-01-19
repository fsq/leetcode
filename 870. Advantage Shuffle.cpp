class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        vector<pair<int,int>> s, t;
        for (int i=0; i<b.size(); ++i) s.push_back({b[i], i});
        sort(s.begin(), s.end());
        
        vector<int> use(a.size());
        int j = 0;
        for (int i=0; j<s.size() && i<a.size(); ) {
            while (i<a.size() && a[i]<=s[j].first) ++i;
            if (i<a.size()) {
                use[i] = true;
                t.push_back({s[j].second, a[i]});
                ++j, ++i;
            }
        }

        for (int i=0; j<b.size(); ++j) {
            while (use[i]) ++i;
            t.push_back({s[j].second, a[i++]});
        }
        sort(t.begin(), t.end());
        vector<int> ans;
        for (int i=0; i<t.size(); ++i) ans.push_back(t[i].second);
        return ans;
    }
};