class Solution {
public:
    vector<int> frequencySort(vector<int>& a) {
        unordered_map<int, int> f;
        for (auto x : a) ++f[x];
        sort(a.begin(), a.end(), [&](int x, int y) {
            return f[x] < f[y] || f[x]==f[y] && x>y;
        });
        return a;
    }
};