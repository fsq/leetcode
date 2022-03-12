class Solution {
public:
    
    long long le(vector<int>& a, vector<int>& b, long long k) {
        if (a.empty() || b.empty()) return 0;
        long long ans = 0;
        for (int i=0,j=b.size()-1; i<a.size(); ++i) {
            while (j>=0 && (long long)a[i]*b[j]>k) --j;
            ans += j+1;
        }
        return ans;
    }
    
    long long ge(vector<int>& a, vector<int>& b, long long k) {
        if (a.empty() || b.empty()) return 0;
        long long ans = 0;
        for (int i=0,j=b.size()-1; i<a.size(); ++i) {
            while (j>=0 && (long long)a[i]*b[j]>=k) --j;
            ans += b.size()-j-1;
        }
        return ans;
    }
    
    long long kthSmallestProduct(vector<int>& a, vector<int>& b, long long k) {
        vector<int> na, pa, nb, pb;
        for (auto x : a)
            if (x < 0)
                na.push_back(-x);
            else
                pa.push_back(x);
        for (auto x : b)
            if (x < 0)
                nb.push_back(-x);
            else
                pb.push_back(x);
        reverse(na.begin(), na.end());
        reverse(nb.begin(), nb.end());
        
        long long l = -10000000000, r = 10000000000;
        while (l < r) {
            long long mid = (l + r) >> 1;
            long long cnt = 0;
            cnt = le(pa, pb, mid) + le(na, nb, mid) +
                  ge(na, pb, -mid) + ge(pa, nb, -mid);
            if (cnt < k) {
                l = mid + 1; 
            } else {
                r = mid;
            }
        }
        return l;
    }
};