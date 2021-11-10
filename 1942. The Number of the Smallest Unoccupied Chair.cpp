class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<vector<int>> e;
        set<int> st;
        vector<int> seat(times.size()+1);
        for (int i=0; i<times.size(); ++i) {
            st.insert(i);
            e.push_back({times[i][0], i+1});
            e.push_back({times[i][1], -(i+1)});
        }
        sort(e.begin(), e.end());
        for (auto& p : e) {
            int x = p[1];
            if (x < 0) {
                st.insert(seat[-x]);
            } else {
                seat[x] = *st.begin();
                st.erase(st.begin());
                if (x == targetFriend+1) return seat[x];
            }
        }
        return 0;
    }
};