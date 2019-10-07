class Solution {
public:
    int longestSubsequence(vector<int>& arr, int df) {
        unordered_map<int, int> m;
        int ans = 0;
        for (auto x : arr)
            ans = max(ans, m[x] = m[x-df]+1);
        return ans;
    }
};