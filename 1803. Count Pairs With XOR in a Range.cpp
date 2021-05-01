class Node {
public:
    Node():son(2, nullptr), c(0) {}
    vector<Node*> son;
    int c;
};

class Solution {
public:
    
    int findLess(Node* p, int mx, int x) {
        int ans = 0;
        for (int i=14; i>=0 && p; --i) {
            int mb = (mx >> i) & 1;
            int xb = (x >> i) & 1;
            if (mb) {
                if (p->son[xb]) ans += p->son[xb]->c;
                p = p->son[1^xb];
            } else {
                p = p->son[xb];
            }
        }
        return ans;
    }
    
    int countPairs(vector<int>& nums, int low, int high) {
        Node* root = new Node();
        
        int ans = 0;
        for (auto x : nums) {
            int h = findLess(root, high+1, x), l = findLess(root, low, x);
            ans += h - l;
            auto p = root;
            for (int i=14; i>=0; --i) {
                int b = (x>>i) & 1;
                if (p->son[b]==nullptr) {
                    p->son[b] = new Node();
                }
                p = p->son[b];
                ++p->c;
            }
        }
        return ans;
    }
};