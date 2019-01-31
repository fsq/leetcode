class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> cnt;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j)
            ++cnt[ a[i] & a[j] ];
        int ans = 0;
        for (auto x : a)
            for (auto& kv : cnt)
                if ((x & kv.first)==0)
                    ans += kv.second;
        return ans;
    }
};