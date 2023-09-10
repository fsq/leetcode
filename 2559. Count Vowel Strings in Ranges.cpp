class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vo = {'a','e','i', 'o','u'};
        vector<int> a;
        for (auto& s : words) {
            a.push_back((vo.count(s[0]) && vo.count(s.back())) ? 1 : 0);
        }
        for (int i=1; i<a.size(); ++i) a[i] += a[i-1];
        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(a[q[1]] - (q[0]==0 ? 0 : a[q[0]-1]));
        }
        return ans;
    }
};