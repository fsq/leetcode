class Solution {
public:
    int missingNumber(vector<int>& a) {
        int d1 = a[1]-a[0], d2 = a[2]-a[1];
        int d = d1<0 ? max(d1, d2) : min(d1, d2);
        for (int i=1; i<a.size(); ++i)
            if (a[i] != a[i-1] + d)
                return a[i-1] + d;
        return 0;
    }
};