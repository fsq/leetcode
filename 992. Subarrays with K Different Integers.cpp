class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int n = a.size(), ans = 0, l=-1, r=-1;
        vector<int> ls(n+1), le(n+1);
        int nls=0, nle=0;
        
        for (int i=0; l<n && i<n; ++i) {
            while (nls<k && l+1<n)  
                if (++ls[a[++l]]==1)
                    ++nls;
            while (r+1<n && (nle<k || (nle==k && le[a[r+1]]))) 
                if (++le[a[++r]]==1)
                    ++nle;
            if (nls==k) ans += r - l + 1;
            if (--ls[a[i]]==0) --nls;
            if (--le[a[i]]==0) --nle;
        }
        return ans;
    }
};