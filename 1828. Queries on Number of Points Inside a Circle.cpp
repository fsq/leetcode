class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& a, vector<vector<int>>& q) {
        vector<int> ans;
        for (auto& cir : q) {
            int c = 0;
            for (auto& p : a) {
                int dx = abs(p[0] - cir[0]), dy = abs(p[1] - cir[1]);
                if (dx*dx+dy*dy <= cir[2]*cir[2])
                    ++c;
            }
            ans.push_back(c);
        }
        return ans;
    }
};