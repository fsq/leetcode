struct Node {
    int id = -1;
    Node* s[26];
    ~Node() {
        for (int i=0; i<26; ++i) delete s[i];
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& ws, vector<string>& ss) {
        Node* root = new Node();
        for (int id=0; id<ws.size(); ++id) {
            auto& w = ws[id];
            auto cur = root;
            if (cur->id == -1 || w.size()<ws[cur->id].size()) cur->id = id;
            for (int i=w.size()-1; i>=0; --i) {
                if (!cur->s[w[i]-'a']) {
                    cur->s[w[i]-'a'] = new Node();
                }
                cur = cur->s[w[i]-'a'];
                if (cur->id == -1 || w.size()<ws[cur->id].size()) cur->id = id;
            }
        }
        vector<int> ans;
        for (auto& s : ss) {
            auto cur = root;
            int ret = cur->id;
            for (int i=s.size()-1; i>=0; --i) {
                if (cur->s[s[i]-'a']) {
                    cur = cur->s[s[i]-'a'];
                    ret = cur->id;
                } else
                    break;
            }
            ans.push_back(ret);
        }
        delete root;
        return ans;
    }
};