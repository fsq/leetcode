class Solution {
public:

    vector<int> GetNext(string& a) {
        vector<int> next(a.size());
        int i=1, j=0;
        while (i < a.size())
            if (a[i] == a[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j-1];
            } else {
                ++i;
            }
        return next;
    }

    vector<int> kmp(string& s, string& a) {
        auto next = GetNext(a);
        vector<int> ans;
        int i=0, j=0;
        while (i < s.size())
            if (s[i] == a[j]) {
                ++i, ++j;
                if (j == a.size()) {
                    ans.push_back(i - j);
                    j = next[j-1];
                }
            } else if (j > 0) {
                j = next[j-1];
            } else {
                ++i;
            }
        return ans;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        auto pa = kmp(s, a);
        auto pb = kmp(s, b);
        vector<int> ans;
        int p = 0;
        for (auto x : pa) {
            while (p<pb.size() && pb[p]<=x) ++p;
            if ((p<pb.size() && pb[p]-x<=k) || (p>0 && x-pb[p-1]<=k)) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};