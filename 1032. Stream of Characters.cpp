class Node {
public:
    Node():has(false), child(26) {}
    bool has;
    vector<Node*> child;
};

class StreamChecker {
public:
    
    Node* root;
    string s;
    
    void insert(const string& s) {
        auto now = root;
        for (auto it=s.rbegin(); it!=s.rend(); ++it) {
            char c = *it;
            if (!now->child[c-'a'])
                now->child[c-'a'] = new Node();
            now = now->child[c-'a'];
        }
        now->has = true;
    }
    
    StreamChecker(vector<string>& words) {
        root = new Node();
        for (auto& w : words)
            insert(w);
    }
    
    bool query(char letter) {
        s.push_back(letter);
        auto now = root;
        for (auto it=s.rbegin(); it!=s.rend(); ++it) {
            char c = *it;
            if (now->child[c-'a']) {
                now = now->child[c-'a'];
                if (now->has) return true;
            } else
                return false;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */