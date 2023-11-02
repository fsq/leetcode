class Solution {
public:
    int beautifulSubsets(vector<int>& a, int k) {
        vector<int> b;
        for (int i=0; i<a.size(); ++i)
            for (int j=i+1; j<a.size(); ++j)
                if (abs(a[i]-a[j]) == k) {
                    int m = (1<<i) | (1<<j);
                    b.push_back(m);
                }
        int ans = 0;
        for (int i=1; i<(1<<a.size()); ++i) {
            if (all_of(b.begin(), b.end(), [i](int x){
                return (i&x) != x;
            })) {
                ++ans;
            }
        }
        return ans;
    }
};