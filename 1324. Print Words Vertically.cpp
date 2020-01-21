class Solution {
public:
    vector<string> printVertically(string s) {
        istringstream str(s);
        vector<string> ws;
        int l = 0;
        for (string w; str>>w; ) {
            ws.push_back(w);
            l = max<int>(l, w.size());
        }
        vector<string> ans(l);
        for (int p=0; p<l; ++p)
            for (int i=0; i<ws.size(); ++i)
                ans[p] += ws[i].size()<=p ? ' ' : ws[i][p];
        for (auto& w : ans)
            while (w.back()==' ') w.pop_back();
        return ans;
    }
};