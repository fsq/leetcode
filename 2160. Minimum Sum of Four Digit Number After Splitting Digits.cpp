class Solution {
public:
    int minimumSum(int num) {
        vector<int> a(4);
        a[0] = num/1000;
        a[1] = num/100%10;
        a[2] = num%100/10;
        a[3] = num%10;
        int ans = INT_MAX;
        sort(a.begin(), a.end());
        do {
            ans = min(ans, a[0]*10+a[1] + a[2]*10+a[3]);
        } while (next_permutation(a.begin(), a.end()));
        return ans;
    }
};