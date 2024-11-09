class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, vector<int>> m;
        for (int i=0, j; i<s.size(); i=j) {
            for (j=i; j<s.size() && s[j]==s[i]; ++j);
            auto& a = m[s[i]];
            a.push_back(j-i);
            sort(a.rbegin(), a.rend());
            if (a.size() > 3) a.pop_back();
        }
        int ans = -1;
        for (auto& [_, a] : m) {
            for (auto x : a) cout << x << ' '; cout << endl;
            int cur = -1;
            if (a.size() == 3) cur = a.back();
            if (a.size() >= 2) {
                if (a[0]-1 >= a[1])
                    cur = max(cur, a[1]);
                else
                    cur = max(cur, a[1]-1);
            } 
            cur = max(cur, a[0] - 2);
            ans = max(ans, cur);
        }
        return ans>0 ? ans : -1;
    }
};