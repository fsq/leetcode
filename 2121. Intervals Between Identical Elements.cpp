class Solution {
public:
    vector<long long> getDistances(vector<int>& a) {
        unordered_map<int, vector<long long>> m;
        vector<long long> ans(a.size());
        for (int i=0; i<a.size(); ++i) 
            m[a[i]].push_back(i);
        for (auto& pr : m) {
            auto a = pr.second;
            long long sum = accumulate(a.begin(), a.end(), 0ll), pre = 0;
            for (long long i=0; i<a.size(); ++i) {
                long long c = sum - pre - a[i] - (a.size()-i-1)*a[i] + a[i]*i - pre;
                ans[a[i]] = c;
                pre += a[i];
            }
        }
        return ans;
    }
};