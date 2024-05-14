class Solution {
public:
    int maxSum(vector<int>& a) {
        int ans = -1;
        for (int i=0; i<a.size(); ++i) {
            string si = to_string(a[i]);
            char x = *max_element(si.begin(), si.end());
            for (int j=i+1; j<a.size(); ++j) {
                string sj = to_string(a[j])                ;
                char y = *max_element(sj.begin(), sj.end());
                if (x == y) {
                    ans = max(ans, a[i] + a[j]);
                }
            }
        }
        return ans;
    }
};