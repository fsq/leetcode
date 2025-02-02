class Solution {
public:
    int minOperations(vector<int>& a) {
        int ans = 0;
        for (int i=0; i+2<a.size(); ++i)
            if (a[i] == 0) {
                a[i] ^= 1;
                a[i+1] ^= 1;
                a[i+2] ^= 1;
                ++ans;
            }
        return a[a.size()-1]==1 && a[a.size()-2]==1 ? ans : -1;
    }
};