class Solution {
public:
    int d[27][27];
    const int INF = 0x3f3f3f3f;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        memset(d, 0x3f, sizeof(d));
        for (int i=0; i<original.size(); ++i) {
            d[original[i]-'a'][changed[i]-'a'] = min(d[original[i]-'a'][changed[i]-'a'], cost[i]);
        }
        for (int i=0; i<26; ++i) d[i][i] = 0;
        for (int k=0; k<26; ++k)
            for (int i=0; i<26; ++i)
                for (int j=0; j<26; ++j)
                    if (i!=k && j!=k) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
        long long ans = 0;
        for (int i=0; i<source.size(); ++i) {
            int dis = d[source[i]-'a'][target[i]-'a'];
            if (dis == INF) return -1;
            ans += dis;
        }
        return ans;
    }
};