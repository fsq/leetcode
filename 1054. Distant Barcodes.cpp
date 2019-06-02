class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> cnt(10001);
        for (auto x : barcodes) ++cnt[x];
        vector<pair<int,int>> a;
        for (int i=1; i<=10000; ++i)
            if (cnt[i])
                a.push_back({cnt[i], i});
        sort(a.begin(), a.end(), std::greater<pair<int,int>>());
        
        vector<vector<int>> b(a[0].first);
        int i = 0;
        for (auto& p : a) {
            int x = p.second, cnt = p.first;
            while (cnt) {
                b[i].push_back(x);
                --cnt;
                i = (i+1) % b.size();
            }
        }
        vector<int> ans;
        for (auto& sg : b)
            ans.insert(ans.end(), sg.begin(), sg.end());
        return ans;
    }
};