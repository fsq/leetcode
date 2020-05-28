class Solution {
public:
    int minMoves2(vector<int>& a) {
        int n = a.size();
        nth_element(a.begin(), a.begin()+n/2, a.end());
        int s = *(a.begin()+n/2);
        int ans = 0;
        for (auto x : a) ans += abs(s-x);
        return ans;
    }
};