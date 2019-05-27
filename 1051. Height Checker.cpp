class Solution {
public:
    int heightChecker(vector<int>& a) {
        auto b = a;
        sort(b.begin(), b.end());
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            ans += a[i] != b[i];
        return ans;
    }
};