class Solution {
public:
    vector<int> recoverArray(vector<int>& a) {
        sort(a.begin(), a.end());
        for (int i=1; i<a.size(); ++i) {
            int l0 = a[0], h0 = a[i];
            if (l0==h0 || ((l0 + h0) & 1)) continue;
            int a0 = (l0 + h0) >> 1, k = a0 - l0;
            vector<int> l;
            int p = 0;
            for (int j=0; j<a.size(); ++j)
                if (p==-1 || p==l.size() || a[j]<l[p]+2*k) {
                    l.push_back(a[j]);
                } else if (a[j] == l[p]+2*k) {
                    ++p;
                } else {
                    break;
                }
            if (l.size() == a.size()/2 && p==l.size()) {
                for (auto& x : l) x += k;
                return l;
            }
        }
        return {};
    }
};
