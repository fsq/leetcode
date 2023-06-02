class Solution {
public:
    vector<int> len;

    bool ok(string& s, int limit, int p) {
        int b = to_string(p).size(), tot_len = 0;
        for (int l=1; l<=b; ++l) { // all except last one
            int suffix_len = 3 + l + b;
            if (suffix_len > limit) return false;
            int num_ind = l==b ? (p - pow(10, b-1)) : len[l]; 
            tot_len += (limit - suffix_len) * num_ind;
        }
        return s.size()-tot_len <= limit - (3+b+b);
    }

    vector<string> split(string& s, int limit, int p) {
        vector<string> ans;
        int sid = 0;
        for (int pid=1; pid<=p; ++pid) {
            string suf = "<" + to_string(pid) + "/" + to_string(p) + ">";
            ans.push_back(s.substr(sid, min(limit-suf.size(), s.size()-sid)) + suf);
            sid += limit - suf.size();
        }
        return ans;
    }

    vector<string> splitMessage(string s, int limit) {
        len.resize(to_string(s.size()).size()+1);
        len[1] = 9;
        for (int i=2; i<len.size(); ++i)
            len[i] = len[i-1] * 10;

        for (int ans=1; ans<=s.size(); ++ans) 
            if (ok(s, limit, ans)){
                return split(s, limit, ans);
            }
        return {};
    }
};