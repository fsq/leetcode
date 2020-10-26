class Solution {
public:
    char slowestKey(vector<int>& a, string b) {
        vector<int> s(26);
        int mx=0;
        char c;
        for (int i=0; i<b.size(); ++i) {
            int d = i==0 ? a[i] : a[i] - a[i-1];
            if (d > mx || d==mx && b[i]>c) {
                c = b[i];
                mx = d;
            }
        }
        return c;
    }
};