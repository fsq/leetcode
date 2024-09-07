class Solution {
public:
    long long minSum(vector<int>& a, vector<int>& b) {
        long long min1=0, min2=0;
        bool z1=false, z2=false;
        for (int i=0; i<a.size(); ++i) {
            if (a[i] == 0) {
                min1 += 1;
                z1 = true;
            } else {
                min1 += a[i];
            }
        }
        for (int i=0; i<b.size(); ++i) {
            if (b[i] == 0) {
                min2 += 1;
                z2 = true;
            } else {
                min2 += b[i];
            }
        }
        if (min1>min2 && !z2 || min1<min2 && !z1) return -1;
        return max(min1, min2);
    }
};