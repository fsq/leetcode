class Solution {
public:
    int kIncreasing(vector<int>& a, int k) {
        int ans = 0;
        for (int first=0; first<k; ++first) {
            vector<int> h;
            int cnt = 0;
            for (int i=first; i<a.size(); i+=k) {
                ++cnt;
                int j = upper_bound(h.begin(), h.end(), a[i]) - h.begin();
                if (j == h.size()) {
                    h.push_back(a[i]);
                } else {
                    h[j] = a[i];
                }
            }
            ans += cnt - h.size();
        }
        return ans;
    }
};