class Solution {
public:
    int minimumPushes(string w) {
        unordered_map<char, int> f;
        for (auto c : w) ++f[c];
        vector<int> a;
        for (auto& pr : f) a.push_back(pr.second);
        sort(a.rbegin(), a.rend());
        int v=1, c=0, ans=0;
        for (auto x: a) {
            ans += x * v;
            if (++c == 8) {
                c = 0;
                ++v;
            }
        }
        return ans;
    }
};