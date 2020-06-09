class BrowserHistory {
public:
    vector<string> a;
    int n = 0, i = 0;
    BrowserHistory(string homepage) {
        a.push_back(homepage);
        n = 1;
    }
    
    void visit(string url) {
        ++i;
        n = i + 1;
        if (a.size() < n)
            a.push_back(url);
        else 
            a[i] = url;
    }
    
    string back(int steps) {
        i = max(0, i-steps);
        return a[i];
    }
    
    string forward(int steps) {
        i = min(n-1, i+steps);
        return a[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */