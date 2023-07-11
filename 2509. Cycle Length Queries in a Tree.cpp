class Solution {
public:

    string f(int x) {
        string ans;
        while (x) {
            ans.push_back((x & 1) + '0');
            x >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& pr : queries) {
            int x = pr[0], y = pr[1];
            string m1 = f(x), m2 = f(y);
            int i = 0;
            for (i=0; i<min(m1.size(), m2.size()); ++i)
                if (m1[i] != m2[i]) {
                    break;
                }
            int len = m1.size()-i + m2.size()-i;
            ans.push_back(len + 1);
        }
        return ans;
    }
};