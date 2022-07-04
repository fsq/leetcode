class Solution {
public:
    int minSwaps(vector<int>& a) {
        int c = count(a.begin(), a.end(), 1);
        if (c <= 1) return 0;
        int s = accumulate(a.begin(), a.begin()+c-1, 0), ans = a.size();
        for (int l=0; l<a.size(); ++l) {
            if (l > 0) s -= a[l-1];
            s += a[(l + c - 1) % a.size()];
            ans = min(ans, c - s);
        }
        return ans;
    }
};