class Solution {
public:
    long long findTheArrayConcVal(vector<int>& a) {
        long long ans = 0;
        for (int i=0, j=a.size()-1; i<=j; ++i, --j)
            if (i == j) {
                ans += a[i];
            } else {
                ans += stoll(to_string(a[i]) + to_string(a[j]));
            }
        return ans;
    }
};