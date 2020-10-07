class Solution {
public:
    int specialArray(vector<int>& a) {
        sort(a.begin(), a.end());
        for (int i=0, ans=0; ans<=a.size(); ++ans) {
            while (i<a.size() && a[i]<ans) ++i;
            if (ans == a.size() - i) return ans;
        }
        return -1;
    }
};