class Solution {
public:
    int minimizeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        return min(a[a.size()-2] - a[1], min(a.back()-a[2], a[a.size()-3]-a[0]));
    }
};

