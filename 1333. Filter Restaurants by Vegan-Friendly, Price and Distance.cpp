class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& re, int ve, int mx_price, int mx_dist) {
        vector<int> id;
        for (int i=0; i<re.size(); ++i)
            if (!(ve && !re[i][2] || re[i][3]>mx_price || re[i][4]>mx_dist))
                id.push_back(i);
        sort(id.begin(), id.end(), [&](int x, int y) {
            return re[x][1] > re[y][1] || re[x][1]==re[y][1] && re[x][0]>re[y][0];
        });
        vector<int> ans;
        for (auto x : id) ans.push_back(re[x][0]);
        return ans;
    }
};