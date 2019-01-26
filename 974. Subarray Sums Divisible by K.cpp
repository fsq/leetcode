class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        unordered_map<int, int> r;
        ++r[0];
        int ans = 0;
        for (int i=0,s=0; i<a.size(); ++i) {
            s += a[i];
            ans += r[s % k];
            if (s%k != 0)
                ans += s>0 ? r[s%k-k] : r[s%k+k];
            ++r[s % k];
        }
        
        return ans;
    }
};