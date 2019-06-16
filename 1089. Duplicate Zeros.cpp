class Solution {
public:
    void duplicateZeros(vector<int>& a) {
        for (int x=0, i=0; i<a.size(); ++i) {
            a[i] += a[i-x]%10*10;
            if (a[i]/10 == 0) {
                ++i;
                ++x;
            }
        }
        for (auto& x : a) x = x / 10;
    }
};