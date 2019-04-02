class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& a) {
        int s = accumulate(a.begin(), a.end(), 0);
        if (s % 3 != 0) return false;
        int p=-1, q=-1;
        for (int pre=0, i=0; i+1<a.size(); ++i) {
            pre += a[i];
            if (pre==s/3 && p==-1)
                p = i;
            if (pre==s/3 * 2)
                q = i;
        }
        return p>=0 && q>=0 && q>p;
    }
};