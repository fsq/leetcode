class Solution {
public:
    int minMutation(string start, string end, vector<string>& vd) {
        unordered_set<string> st(vd.begin(), vd.end());
        if (st.count(start)) st.erase(st.find(start));
        if (!st.count(end)) return -1;
        string p = "ACGT";
        queue<string> q;
        q.push(start);
        for (int stp=1; q.size(); ++stp)
            for (int t=q.size(); t; --t) {
                string now = move(q.front()); q.pop();
                for (int i=0; i<8; ++i)
                    for (auto c : p)
                        if (c != now[i]) {
                            string nxt = now;
                            nxt[i] = c;
                            if (nxt == end) return stp;
                            if (st.count(nxt)) {
                                q.push(nxt);
                                st.erase(nxt);
                            }
                        }
            }
        return -1;
        
    }
};