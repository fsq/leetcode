class Solution {
public:
    int minSumOfLengths(vector<int>& a, int target) {
        vector<int> pre(a.size(), INT_MAX);
        int ans = INT_MAX;
        for (int l=0, r=0, s=0; r<a.size(); ++r) {
            s += a[r];
            while (s > target) 
                s -= a[l++];
            
            if (r>0) pre[r] = pre[r-1];
            if (s==target) {
                pre[r] = min(pre[r], r-l+1);
                if (l>0 && pre[l-1]!=INT_MAX) ans = min(ans, r-l+1 + pre[l-1]);
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};