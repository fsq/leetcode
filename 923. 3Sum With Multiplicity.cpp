class Solution {
public:
    const int M = 1e9 + 7;
    int threeSumMulti(vector<int>& a, int target) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            vector<int> cnt(101);
            int tar = target - a[i];
            for (int j=a.size()-1; j>i; --j) {
                int rem = tar - a[j];
                if (rem>=0 && rem<=100) 
                    ans = (ans + cnt[rem]) % M;
                cnt[a[j]]++;
            }
        }
        return ans;
    }
};