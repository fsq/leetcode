class Solution {
public:
    
    int cut(const vector<int>& a, int c) {
        int ans = 0;
        for (int i=0, s; i<a.size(); ) {
            s = 0;
            while (s < c && i<a.size()) s += a[i++];
            if (s < c) return ans-1;
            if (i!=a.size()) ++ans;
        }
        return ans;
    }
    
    int maximizeSweetness(vector<int>& a, int k) {
        if (k==0) return accumulate(a.begin(), a.end(), 0);
        
        int l=1, r=accumulate(a.begin(), a.end(), 0);
        while (l < r) {
            int mid = (l+r+1) >> 1;
            int kt = cut(a, mid);
            if (kt >= k) 
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};