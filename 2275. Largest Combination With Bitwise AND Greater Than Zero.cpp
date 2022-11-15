class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> a(33);
        for (auto x : candidates) {
            for (int i=0; i<32; ++i) a[i] += (x >> i) & 1;
        }
        return *max_element(a.begin(), a.end());
    }
};