class Solution {
public:
    int triangularSum(vector<int>& a) {
        while (a.size() > 1) {
            vector<int> b(a.size()-1);
            for (int i=0; i<b.size(); ++i) b[i] = (a[i] + a[i+1]) % 10;
            a.swap(b);
        }
        return a[0];
    }
};