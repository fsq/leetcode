class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        vector<int> last(3);
        int tot = 0;
        for (int i=0; i<g.size(); ++i) {
            tot += g[i].size();
            if (find(g[i].begin(), g[i].end(), 'M') != g[i].end()) last[0] = i;
            if (find(g[i].begin(), g[i].end(), 'P') != g[i].end()) last[1] = i;
            if (find(g[i].begin(), g[i].end(), 'G') != g[i].end()) last[2] = i;
        }
        int ans = 0;
        for (int i=0; i+1<g.size(); ++i) {
            int c = 0;
            for (int j=0; j<3; ++j)
                if (i < last[j])
                    ++c;
            ans += t[i] * c;
            if (c == 0) break;
        }
        return ans + tot;
    }
};