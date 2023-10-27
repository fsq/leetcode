class Solution {
public:
    int maximizeGreatness(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=0,j=0; j<a.size(); ++i) {
            while (j<a.size() && a[j]<=a[i]) ++j;
            if (j<a.size()) {
                ++ans;
                ++j;
            }
        }
        return ans;
    }
};