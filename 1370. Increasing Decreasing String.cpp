class Solution {
public:
    string sortString(string s) {
        vector<int> a(26);
        for (auto x : s) ++a[x-'a'];
        string ans;
        for (int d=1,j=0; ans.size()<s.size(); ) {
            if (a[j]>0) {
                ans.push_back(j+'a');
                --a[j];
            }
            j += d;
            if (j<0 || j>25) {
                d *= -1;
                j += d;
            }
        }
        return ans;
    }
};