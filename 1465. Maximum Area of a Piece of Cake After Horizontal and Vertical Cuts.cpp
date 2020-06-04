class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        long maxh = max(hc[0], h - hc.back()), maxw = max(vc[0], w - vc.back());
        for (int i=0; i+1<hc.size(); ++i) maxh = max<long long>(maxh, hc[i+1]-hc[i]);
        for (int i=0; i+1<vc.size(); ++i) maxw = max<long long>(maxw, vc[i+1]-vc[i]);
        return maxh * maxw % 1000000007;
    }
};