class Solution {
public:

    int numberOfBeams(vector<string>& a) {
        int pre = 0, ans = 0;
        for (int i=0; i<a.size(); ++i) {
            int cur = count(a[i].begin(), a[i].end(), '1');
            if (cur > 0) {
                ans += pre * cur;
                pre = cur;
            }
        }
        return ans;
    }
};