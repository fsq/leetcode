class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        set<int> st(persons.begin(), persons.end());
        unordered_map<int, int> c;

        map<int, int> m;
        for (auto& f : flowers)
            ++m[f[0]], --m[f[1]+1];
        auto it = m.begin();
        int cnt = 0;
        for (auto x : st) {
            while (it!=m.end() && it->first<=x) {
                cnt += it->second;
                ++it;
            }
            c[x] = cnt;
        }

        vector<int> ans;
        for (auto x : persons)
            ans.push_back(c[x]);
        return ans;
    }
};