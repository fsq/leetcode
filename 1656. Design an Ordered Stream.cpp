class OrderedStream {
public:
    vector<string> a;
    int p = 1;
    OrderedStream(int n) {
        a.resize(n+1);
    }
    
    vector<string> insert(int id, string value) {
        vector<string> ans;
        a[id] = value;
        if (!a[p].empty()) {
            for (p; p<a.size() && a[p].size(); ++p)
                ans.push_back(a[p]);
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */