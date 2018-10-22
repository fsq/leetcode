class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        for (int p=0, i=0; p<a.size(); ) {
            if (!(a[i] & 1)) {
                swap(a[i], a[p]);
                p += 2;
            }
            i += 2;
            if (i>=a.size()) i = 1;
        }
        return a;
    }
};