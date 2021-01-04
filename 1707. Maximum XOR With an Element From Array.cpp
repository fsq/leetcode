struct Node {
    Node() {
        mn = INT_MAX;
    }
    int mn;
    vector<Node*> son = {nullptr, nullptr};
};

class Solution {
public:
    int hibit = 0;
    Node* root;
    
    void insert(int x) {
        Node* cur = root;
        for (int i=hibit; i>=0; --i) {
            int b = (x>>i) & 1;
            if (cur->son[b] == nullptr) {
                cur->son[b] = new Node();
                cur->son[b]->mn = x;
            }
            cur->mn = min(cur->mn, x);
            cur = cur->son[b];
        }
    }
    
    int query(int x, int limit) {
        Node* cur = root;
        int num = 0, ans = x - (x & ((1<<(hibit+1))-1));
        for (int i=hibit; i>=0; --i) {
            int b  = (x>>i) & 1, nxt;
            if (cur->son[b ^ 1] && num+((b^1)<<i)<=limit && cur->son[b^1]->mn<=limit)
                nxt = b ^ 1;
            else
                nxt = b;

            num += nxt << i;
            ans += (b ^ nxt) << i;
            cur = cur->son[nxt];
        }       
        return ans;
    }
    
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& q) {
        root = new Node();
        int m = INT_MAX, limit = 0;

        for (auto& pr : q)
            limit = max(limit, pr[1]);
        
        for (auto x : a)
            for (int i=31; i>hibit; --i)
                if ((x>>i) & 1) {
                    hibit = i;
                    break;
                }
        for (auto x : a) 
            if (x <= limit) {
                insert(x);
                m = min(m, x);
            }
        vector<int> ans;
        for (auto& pr : q) {
            ans.push_back(pr[1]>=m ? query(pr[0], pr[1]) : -1);
        }
        return ans;
    }
};
