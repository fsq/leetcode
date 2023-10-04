class Solution {
public:
    vector<int> leftRightDifference(vector<int>& a) {
        int rs = accumulate(a.begin(), a.end(), 0), ls = 0;
        vector<int> ans;
        for (int i=0; i<a.size(); ++i) {
            rs -= a[i];
            ans.push_back(abs(ls-rs));
            ls += a[i];
        }
        return ans;
    }
};