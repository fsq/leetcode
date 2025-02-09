const int inf = 0x3f3f3f3f;

class Solution {
public:

    struct Node {
        int cost = inf;
        Node* c[26] = {nullptr};
        int l = 0;
        Node* suffix_link = nullptr; // link to the longest suffix node
        Node* cost_suffix_link = nullptr; // link to the longest suffix node where cost!=inf
    };

    int minimumCost(string target, vector<string>& ws, vector<int>& cs) {
        auto* root = new Node();
        // build trie
        for (int i=0; i<ws.size(); ++i) {
            auto& w = ws[i];
            auto cost = cs[i];
            auto cur = root;
            int l = 0;
            for (auto c : w) {
                if (!cur->c[c-'a']) {
                    cur->c[c-'a'] = new Node();
                }
                cur = cur->c[c-'a'];
                ++l;
                cur->l = l;
            }
            cur->cost = min(cur->cost, cost);
        }
        // compute suffix link and transition
        root->suffix_link = root->cost_suffix_link = root;
        queue<Node*> q;
        for (auto c=0; c<26; ++c) {
            if (root->c[c]) {
                root->c[c]->suffix_link = root;
                root->c[c]->cost_suffix_link = root;
                q.push(root->c[c]);
            } else {
                root->c[c] = root;
            }
        }
        while (q.size()) {
            auto u = q.front(); q.pop();
            auto v = u->suffix_link;
            for (auto c=0; c<26; ++c)
                if (u->c[c]) {
                    auto tu = u->c[c];
                    auto tv = v->c[c];
                    tu->suffix_link = tv;
                    tu->cost_suffix_link = tv->cost==inf ? tv->cost_suffix_link : tv;
                    q.push(tu);
                } else {
                    u->c[c] = v->c[c];
                }
        }
        // dp
        vector<int> f(target.size(), inf);
        auto cur = root;
        for (int i=0; i<target.size(); ++i) {
            auto x = target[i] - 'a';
            cur = cur->c[x];
            auto u = cur->cost==inf? cur->cost_suffix_link : cur;
            for (; u!=root; u=u->cost_suffix_link)
                f[i] = min(f[i], (u->l<=i ? f[i-u->l] : 0) + u->cost);
        }
        return f.back()==inf ? -1 : f.back();
    }
};