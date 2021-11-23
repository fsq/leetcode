class Solution {
public:
    struct Node {
        string name;
        bool del = false;
        map<string, Node*> son;
        Node(string n):name(std::move(n)) {}
    };
    
    unordered_map<string, Node*> h;
    
    string f(Node* now) {
        if (!now) return "";
        string s;
        for (auto sn : now->son) {
            s += f(sn.second);
        }
        if (!s.empty()) {
            auto it = h.find(s);
            if (it == h.end()) {
                h[s] = now;
            } else {
                h[s]->del = true;
                now->del = true;
            }
        }
        return now->name + "(" + s + ")";
    }
    
    vector<vector<string>> ans;
    void dfs(Node* now, vector<string>& cur) {
        if (!now || now->del) return;
        if (!cur.empty()) ans.push_back(cur);
        for (auto sn : now->son) {
            cur.push_back(sn.first);
            dfs(sn.second, cur);
            cur.pop_back();
        }
        
    }
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node root("");
        for (const auto& p : paths) {
            auto now = &root;
            for (const auto& w : p) {
                if (!now->son.count(w)) {
                    now->son[w] = new Node(w);
                }
                now = now->son[w];
            }
        }
        
        f(&root);
        // cout << root.son["d"]->son["a"]->del;
        vector<string> cur;
        dfs(&root, cur);
        return ans;
    }
};