class Solution {
public:
    vector<int> getMaximumXor(vector<int>& a, int maximumBit) {
        vector<int> ans;
        for (int s=0, i=0; i<a.size(); ++i) {
            s ^= a[i];
            ans.push_back( ((1<<maximumBit)-1) ^ s);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};