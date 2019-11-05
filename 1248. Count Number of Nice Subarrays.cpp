class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        for (auto& x : a) x = x & 1;
        vector<int> m(50001);
        m[0] = 1;
        
        long long ans = 0;
        for (int i=0,s=0; i<a.size(); ++i) {
            s += a[i];
            if (s>=k) ans += m[s-k];
            ++m[s];
        }
        return ans;
    }
};