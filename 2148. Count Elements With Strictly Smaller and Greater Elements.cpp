class Solution {
public:
    int countElements(vector<int>& a) {
        auto pr = minmax_element(a.begin(), a.end());
        if (*pr.first == *pr.second) return 0;
        int ans = a.size();
        ans -= count(a.begin(), a.end(), *pr.first) + count(a.begin(), a.end(), *pr.second);
        return ans;
    }
};