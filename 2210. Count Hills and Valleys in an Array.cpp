class Solution {
public:
    int countHillValley(vector<int>& a) {
        int i = 1, ans = 0;
        while (i+1 < a.size()) {
            int pre = a[i-1];
            while (i+1<a.size() && a[i]==a[i+1]) ++i;
            if (i+1==a.size()) break;
            if (a[i]>pre && a[i]>a[i+1] || a[i]<pre && a[i]<a[i+1]) {
                ++ans;
            } 
            ++i;
        }
        return ans;
    }
};