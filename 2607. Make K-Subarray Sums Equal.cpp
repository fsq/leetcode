class Solution {
public:

    long long equal(vector<long long>& a) {
        int n = a.size();
        nth_element(a.begin(), a.begin()+n/2, a.end());
        long long ans = 0;
        for (auto x : a) ans += abs(x-a[n/2]);
        return ans;
    }

    long long makeSubKSumEqual(vector<int>& a, int k) {
        long long ans = 0;
        vector<int> vis(a.size());
        for (int i=0; i<a.size(); ++i)
            if (!vis[i]) {
                vector<long long> p;
                for (int j=i; !vis[j]; j=(j+k)%a.size()) {
                    p.push_back(a[j]);
                    vis[j] = true;
                }
                ans += equal(p);
            }
        return ans;
    }
};