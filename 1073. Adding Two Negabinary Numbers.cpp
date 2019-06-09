class Solution {
public:
    vector<int> addNegabinary(vector<int>& a, vector<int>& b) {
        if (a.size() < b.size()) swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i=0; i<max(a.size(), b.size()); ++i)
            a[i] += i<b.size() ? b[i] : 0;
        for (int c=0,i=0; i<a.size() || c; ++i) {
            if (i==a.size()) a.push_back(0);
            a[i] += c;
            c = a[i]==-1 ? 1 : (a[i]>1 ? -1 : 0);
            a[i] &= 1;
        }
        while (a.size()>1 && a.back()==0) a.pop_back();
        reverse(a.begin(), a.end());
        return a;
    }
};