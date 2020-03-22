class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        const int B = 1102;
        vector<int> s(2205);
        for (auto x : arr2) ++s[x+B];
        for (int i=1; i<=2*B; ++i) s[i] += s[i-1];
        int ans = 0;
        for (auto x : arr1)
            if (s[x-1+B]==s[x+d+B] && s[x-1+B]==s[x-d-1+B])
                ++ans;
        return ans;
    }
};