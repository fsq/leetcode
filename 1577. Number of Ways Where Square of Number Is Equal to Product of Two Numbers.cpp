class Solution {
public:
    
    int calc(vector<pair<long long,int>>& a, vector<pair<long long,int>>& b) {
        int ans = 0;
        for (auto pa : a) {
            long long x = pa.first, ca = pa.second;
            for (int i = 0, j = b.size()-1; i<=j; ++i) {
                while (i<=j && b[i].first*b[j].first >= x*x) {
                    if (b[i].first * b[j].first == x*x) {
                        ans += ca * (i==j ?  b[i].second * (b[i].second-1)/2 :  b[i].second * b[j].second);
                    }
                    --j;
                }
            }
        }
        return ans;
    }
    
    int numTriplets(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<pair<long long,int>> s, t;
        for (auto x : a)
            if (s.size() && x==s.back().first)
                ++s.back().second;
            else
                s.push_back({x, 1});
        for (auto x : b)
            if (t.size() && x==t.back().first)
                ++t.back().second;
            else
                t.push_back({x, 1});

        return calc(s, t) + calc(t, s);
    }
};