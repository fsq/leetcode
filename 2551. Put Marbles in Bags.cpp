class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        if (w.size()==k) return 0;
        vector<pair<int,int>> a;
        for (int i=0; i+1<w.size(); ++i) {
            a.push_back({w[i]+w[i+1], i});
        }
        sort(a.begin(), a.end());
        long long mx=w.front()+w.back(), mn=w.front()+w.back();
        for (int i=0; i<k-1; ++i) {
            mn += a[i].first;
            mx += a[a.size()-i-1].first;
        }
        return mx - mn;
    }
};