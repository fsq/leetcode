class Solution {
public:
    int minSetSize(vector<int>& a) {
        unordered_map<int, int> m;
        for (auto x : a) ++m[x];
        vector<pair<int,int>> p;
        for (auto& pr : m) p.push_back({pr.second, pr.first});
        sort(p.begin(), p.end(), std::greater<pair<int,int>>());
        int ans = 0, cnt = 0, i = 0;
        while (cnt < a.size() / 2) {
            ++ans;
            cnt += p[i++].first;
        }
        return ans;
    }
};