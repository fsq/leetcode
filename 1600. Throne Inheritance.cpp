class ThroneInheritance {
public:
    
    unordered_map<string, vector<string>> t;
    unordered_set<string> dead;
    string root;
    
    ThroneInheritance(string kingName) {
        root = kingName;
        t[root] = {};
    }
    
    void birth(string parentName, string childName) {
        t[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void dfs(const string& x, vector<string>& ans) {
        if (!dead.count(x))
            ans.push_back(x);
        for (auto& y : t[x])
            dfs(y, ans);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(root, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */