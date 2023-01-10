class Solution {
public:
    int fillCups(vector<int>& a) {
        int s = a[0] + a[1] + a[2];
        return max(max(a[0], max(a[1], a[2])), (s+1)/2);
    }
};