class Solution {
public:
    int reductionOperations(vector<int>& a) {
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int i=1; i<a.size(); ++i)
            if (a[i]<a[i-1])
                ans += i;
        return ans;
    }
};