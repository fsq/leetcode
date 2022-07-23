class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& a) {
        int n1 = accumulate(a.begin(), a.end(), 0);
        int s = 0, mx = n1;
        vector<int> ans = {0};
        for (int i=1; i<=a.size(); ++i) {
            s += a[i-1];
            int c = i - s + n1 - s;
            if (c > mx) {
                mx = c;
                ans = {i};
            } else if (c == mx) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};