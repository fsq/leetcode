class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int numOfSubarrays(vector<int>& arr) {
        vector<int> s(2);
        s[0] = 1;
        int t = 0, ans = 0;
        for (auto x : arr) {
            t ^= (x&1);
            ans = (ans + s[t^1]) % M;
            ++s[t];
        }
        return ans;
    }
};