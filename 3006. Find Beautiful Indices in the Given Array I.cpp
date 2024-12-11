class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> id, ans;
        for (int i=0; i+b.size()<=s.size(); ++i)
            if (equal(b.begin(), b.end(), s.begin()+i)) {
                id.push_back(i);
            }
        for (int p=0,i=0; i+a.size()<=s.size(); ++i) {
            if (!equal(a.begin(), a.end(), s.begin()+i)) continue;
            while (p<id.size() && id[p]<=i) ++p;
            if ((p<id.size() && id[p]-i<=k) || (p>0 && i-id[p-1]<=k)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};