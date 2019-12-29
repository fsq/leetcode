class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        for (int s=-1, i=a.size()-1; i>=0; --i) {
            int t = a[i];
            a[i] = s;
            s = max(t, s);
        }
        return a;
    }
};