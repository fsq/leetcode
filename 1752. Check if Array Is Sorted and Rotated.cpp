class Solution {
public:
    bool check(vector<int>& a) {
        int i = 1;
        while (i<a.size() && a[i]>=a[i-1]) ++i;
        if (i==a.size()) return true;
        int j = i + 1;
        while (j<a.size() && a[j]>=a[j-1]) ++j;
        return j==a.size() && a.back() <= a.front();
    }
};