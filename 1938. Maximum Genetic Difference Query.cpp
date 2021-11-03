class Solution {
public:
    struct Node {
        int cnt;
        Node* c[2];
        Node() {
            c[0] = c[1] = nullptr;
            cnt = 0;
        }
    };
    
    vector<int> ans;
    vector<vector<int>> e, q;
    int n;
    Node* tr;
    
    void dfs(vector<vector<int>>& qs, int x) {
        Node* p = tr;
        for (int i=17; i>=0; --i) {
            int b = x >> i & 1;
            if (p->c[b] == nullptr) 
                p->c[b] = new Node();
            p = p->c[b];
            ++p->cnt;
        }
        for (auto i : q[x]) {
            int val = qs[i][1], t = 0;
            Node* p = tr;
            for (int i=17; i>=0; --i) {
                int b = (val >> i) & 1;
                if (p->c[b^1] && p->c[b^1]->cnt) {
                    t |= 1 << i;
                    p = p->c[b^1];
                } else {
                    p = p->c[b];
                }
            }
            ans[i] = t;
        }
        
        for (auto y : e[x]) dfs(qs, y);
        p = tr;
        for (int i=17; i>=0; --i) {
            int b = x >> i & 1;
            p = p->c[b];
            --p->cnt;
        }
    }
    
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        n = parents.size();
        q.resize(n);
        e.resize(n);
        ans.resize(queries.size());
        int root = 0;
        tr = new Node();
        for (int i=0; i<n; ++i) 
            if (parents[i] == -1) {
                root = i;
            } else {
                e[parents[i]].push_back(i);
            }
        for (int i=0; i<queries.size(); ++i) {
            q[queries[i][0]].push_back(i);
        }
        dfs(queries, root);
        return ans;
    }
};
