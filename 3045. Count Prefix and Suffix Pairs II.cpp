struct Node {
    int cnt = 0;
    vector<Node*> c;
    Node() {
        c.resize(26);
    }
};

class Solution {
public:
    vector<int> getNext(string& s) {
        vector<int> next(s.size());
        int i=1, j=0;
        while (i<s.size())
            if (s[i] == s[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j-1];
            } else {
                ++i;
            }
        return next;
    }

    long long countPrefixSuffixPairs(vector<string>& ws) {
        Node root;
        long long ans = 0;
        for (auto s: ws) {
            auto next = getNext(s);
            vector<int> p = {(int)s.size()};
            for (int i=next.back(); i>0; i=next[i-1]) {
                p.push_back(i);
            }
            auto *cur = &root;
            for (int i=0; i<s.size(); ++i) {
                if (cur->c[s[i]-'a'] == nullptr) {
                    cur->c[s[i]-'a'] = new Node();
                }
                cur = cur->c[s[i]-'a'];
                if (p.size() && i+1==p.back()) {
                    ans += cur->cnt;
                    p.pop_back();
                }
            }
            ++cur->cnt;
        }      
        return ans;
    }
};