class Solution {
public:

    int closestMeetingNode(vector<int>& e, int x, int y) {
        vector<int> d1(e.size(), -1), d2(e.size(), -1);
        for (auto now=x, l=0; now!=-1 && d1[now]==-1; now=e[now], ++l) d1[now] = l;
        for (auto now=y, l=0; now!=-1 && d2[now]==-1; now=e[now], ++l) d2[now] = l;
        int mx = INT_MAX, ans = -1;
        for (int i=0; i<e.size(); ++i)
            if (d1[i]!=-1 && d2[i]!=-1 && max(d1[i], d2[i])<mx) {
                mx = max(d1[i], d2[i]);
                ans = i;
            }
        return ans;
    }
};