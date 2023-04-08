class Solution {
public:
    struct Node {
        Node* s[26] = {};
        int c = 0;
    };

    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node();
        for (auto& w: words) {
            auto now = root;
            for (auto ch : w) {
                if (now->s[ch-'a'] == nullptr) {
                    now->s[ch-'a'] = new Node();
                }
                now = now->s[ch-'a'];
                ++now->c;
            }
        }
        vector<int> ans;
        for (auto& w : words) {
            auto now = root;
            int tot = 0, i = 0;
            for (auto ch : w) {
                now = now->s[ch-'a'];
                if (now->c==1) {
                    tot += w.size() - i;
                    break;
                }
                ++i;
                tot += now->c;
            }
            ans.push_back(tot);
        }
        return ans;
    }
};