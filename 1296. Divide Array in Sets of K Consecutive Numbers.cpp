class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> a;
        for (auto x : nums) ++a[x];
        for (auto it=a.begin(); it!=a.end(); ++it) {
            int x = it->first, cnt = it->second;
            if (cnt==0) continue;
            for (int i=x; i<x+k; ++i) {
                if (a[i]<cnt) return false;
                a[i] -= cnt;
            }
        }
        return true;
    }
};