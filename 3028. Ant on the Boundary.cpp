class Solution {
public:
    int returnToBoundaryCount(vector<int>& a) {
        int s=0, ans=0;
        for (auto x : a) {
            s += x;
            if (s == 0) ++ans;
        }
        return ans;
    }
};