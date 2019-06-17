class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int,int>> a;
        int n = values.size();
        for (int i=0; i<n; ++i)
            a.push_back({values[i], labels[i]});
        sort(a.begin(), a.end(), std::greater<pair<int,int>>());
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i=0; num_wanted && i<n; ++i)
            if (cnt[a[i].second] < use_limit) {
                ans += a[i].first;
                ++cnt[a[i].second];
                --num_wanted;
            }
        return ans;
    }
};