class Solution {
public:
    vector<int> answerQueries(vector<int>& a, vector<int>& qs) {
        sort(a.begin(), a.end());
        vector<int> ans;
        for (auto q : qs) {
            int i = 0, s = 0;
            while (i<a.size() && s+a[i]<=q) {
                s += a[i++];
            }
            ans.push_back(i);
        }
        return ans;
    }
};