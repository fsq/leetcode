class Solution {
public:
    int countPairs(vector<int>& a) {
        unordered_map<int, int> cnt;
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (auto x : a) {
            unordered_set<int> st;
            ans += cnt[x];
            auto s = to_string(x);
            for (int i=0; i<s.size(); ++i)
                for (int j=i; j<s.size(); ++j)
                    for (int p=0; p<s.size(); ++p)
                        for (int q=p; q<s.size(); ++q) {
                            swap(s[i], s[j]); swap(s[p], s[q]);
                            st.insert(stoi(s));
                            swap(s[p], s[q]); swap(s[i], s[j]); 
                        }
            for (auto& x : st) {
                ++cnt[x];
            }
        }
        return ans;
    }
};