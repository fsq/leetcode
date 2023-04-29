class Solution {
public:
    int minimizeArrayValue(vector<int>& num) {
        vector<long long> f(num.size()), a(num.size());
        for (int i=0; i<num.size(); ++i) a[i] = num[i];
        f[0] = a[0];
        for (int i=1; i<a.size(); ++i) {
            if (a[i] > f[i-1]) {
                int md = (a[i]-f[i-1])%(i+1);
                f[i] = f[i-1] + (a[i]-f[i-1])/(i+1) + (md>0 ? 1 : 0);
                if (md>0 && i+1<a.size()) a[i+1] -= (i+1-md);
            } else {
                f[i] = f[i-1];
                if (i+1<a.size()) a[i+1] -= (f[i]-a[i]);
            }
        }
        return f.back();
    }
};