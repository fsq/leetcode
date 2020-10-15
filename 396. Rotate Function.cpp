class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        long long s = 0, tot = 0;
        for (int i=0; i<a.size(); ++i) {
            s += i * a[i];
            tot += a[i];
        }
        
        long long ans = s;
        for (int i=1; i<a.size(); ++i) {
            s = s + tot - a.size() * a[a.size()-i];
            ans = max(ans, s);
        }
        return ans;
    }
};