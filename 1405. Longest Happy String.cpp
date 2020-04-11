class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        set<pair<int,char>, std::greater<pair<int,char>>> st;
        if (a>0) st.insert({a,'a'});
        if (b>0) st.insert({b,'b'});
        if (c>0) st.insert({c,'c'});
        string ans;
        while (!st.empty()) {
            auto pr = *st.begin();
            st.erase(st.begin());
            if (ans.size()>=2 && ans.back()==ans[ans.size()-2] && ans.back()==pr.second) {
                if (st.empty()) break;
                auto p1 = *st.begin();
                st.erase(st.begin());
                st.insert(pr);
                pr = p1;
            }
            ans += pr.second;
            --pr.first;
            if (pr.first) st.insert(pr);
        }
        return ans;
    }
};