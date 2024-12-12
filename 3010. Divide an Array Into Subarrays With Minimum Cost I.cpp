class Solution {
public:
    int minimumCost(vector<int>& a) {
        sort(a.begin()+1, a.end());
        return a[0]+a[1]+a[2];
    }
};