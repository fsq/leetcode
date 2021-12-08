class Solution {
public:
    int findMiddleIndex(vector<int>& a) {
        int s = accumulate(a.begin(), a.end(), 0), cur = 0;
        for (int i=0; i<a.size(); ++i) {
            if (s-cur-a[i] == cur) return i;
            cur += a[i];
        }
        return -1;
    }
};