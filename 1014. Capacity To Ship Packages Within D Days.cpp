class Solution {
public:
    
    int go(vector<int>& a, int c) {
        int d = 0;
        for (int j,sum=0, i=0; i<a.size(); i=j) {
            for (j=i; j<a.size() && sum+a[j]<=c; ++j)
                sum += a[j];
            sum = 0;
            ++d;
        }
        
        return d;
    }
    
    int shipWithinDays(vector<int>& a, int d) {
        int l=*max_element(a.begin(), a.end()), 
            r=accumulate(a.begin(), a.end(), 0);
        while (l < r) {
            int mid = (l+r) >> 1;
            if (go(a, mid)<=d) 
                r = mid;
            else 
                l = mid + 1;
        }
        return l;
    }
};