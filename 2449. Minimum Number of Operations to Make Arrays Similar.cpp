class Solution {
public:

    long long f(vector<int>& a, vector<int>& b) {
        long long ans = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i=0; i<a.size(); ++i)
            if (a[i] > b[i]) {
                ans += max(0, a[i]-b[i])/2;
            }
        return ans;
    }

    long long makeSimilar(vector<int>& a, vector<int>& b) {
        vector<int> a1, a2, b1, b2;
        for (int i=0; i<a.size(); ++i) {
            if (a[i]&1) a1.push_back(a[i]); else a2.push_back(a[i]);
            if (b[i]&1) b1.push_back(b[i]); else b2.push_back(b[i]);
        }
        return f(a1, b1) + f(a2, b2);
    }
};