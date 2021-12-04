class Solution {
public:
    string kthLargestNumber(vector<string>& a, int k) {
        sort(a.begin(), a.end(), [](string& x, string& y) {
            return x.size() > y.size() || x.size()==y.size() && x>y;
        });
        return a[k-1];
    }
};