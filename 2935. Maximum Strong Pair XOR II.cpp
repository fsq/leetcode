struct Node {
    Node* s[2];
    int max = -1;
    Node() {
        s[0] = s[1] = NULL;
    }
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& a) {
        sort(a.begin(), a.end());
        auto *r = new Node();
        int ans = 0;
        for (auto x : a) {
            int limit = (x+1) / 2;
            auto cur = r;
            for (int i=19; i>=0; --i) {
                int b = (x>>i) & 1;
                if (cur->s[b^1] && cur->s[b^1]->max>=limit) {
                    cur = cur->s[b^1];
                } else if (cur->s[b]) {
                    cur = cur->s[b];
                } else {
                    goto add;
                }
            }
            ans = max(ans, x ^ cur->max);

            add:
            cur = r;
            for (int i=19; i>=0; --i) {
                int b = (x>>i) & 1;
                if (!cur->s[b]) {
                    cur->s[b] = new Node();
                }
                cur = cur->s[b];
                cur->max = max(cur->max, x);
            }
        }
        return ans;
    }
};