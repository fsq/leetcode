class Solution {
public:
    
    vector<int> getStrongest(vector<int>& a, int k) {
        int n = a.size();
        nth_element(a.begin(), a.begin()+(n-1)/2, a.end());
        int mid = a[(n-1) / 2];
        nth_element(a.begin(), a.begin()+k, a.end(), [=](int x, int y) {
            int di = abs(x-mid), dj = abs(y-mid);
            return (di > dj) || (di==dj && x>y);
        });
        a.resize(k);
        return a;
    }
};