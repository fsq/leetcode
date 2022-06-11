class Solution {
public:
    
    int f(vector<vector<int>>& a, int start, int k) {
        int i = 0; // leftest within k/2
        while (2*(start-a[i][0])>k) ++i;
        int j = i, s = 0;
        while (j<a.size() && start-a[i][0]+a[j][0]-a[i][0]<=k) {
            s += a[j][1];
            ++j;
        }
        int ans = s;
        while (i+1<a.size() && a[i+1][0]<=start) {
            s -= a[i][1];
            ++i;
            while (j<a.size() && start-a[i][0]+a[j][0]-a[i][0]<=k) {
                s += a[j][1];
                ++j;
            }
            ans = max(ans, s);
        }
        return ans;
    }
    
    int maxTotalFruits(vector<vector<int>>& a, int startPos, int k) {
        int ins = 0;
        for (ins=0; ins<a.size(); ++ins)
            if (a[ins][0]>=startPos) break;
        // insert [startPos, 0]
        if (ins==a.size() || a[ins][0] != startPos) {
            a.insert(a.begin()+ins, {startPos, 0});
        }
        int ans1 = f(a, startPos, k);
        int maxp = a.back()[0];
        reverse(a.begin(), a.end());
        for (auto& x : a) x[0] = maxp - x[0];
        int ans2 = f(a, maxp-startPos, k);
        return max(ans1, ans2);
    }
};