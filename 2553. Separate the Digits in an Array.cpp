class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto it=nums.rbegin(); it!=nums.rend(); ++it) {
            int x = *it;
            while (x) {
                ans.push_back(x % 10);
                x /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};