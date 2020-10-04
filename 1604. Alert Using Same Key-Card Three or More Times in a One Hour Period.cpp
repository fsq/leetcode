class Solution {
public:
    vector<string> alertNames(vector<string>& a, vector<string>& b) {
        unordered_map<string, vector<int>> m;
        for (int i=0; i<a.size(); ++i) 
            m[a[i]].push_back(stoi(b[i].substr(0,2))*60 + stoi(b[i].substr(3,2)));
        
        set<string> ans;
        for (auto& pr : m) {
            auto& a = pr.second;
            sort(a.begin(), a.end());
            for (int i=0; i+2<a.size(); ++i)
                if (a[i+2]-a[i]<=60) {
                    ans.insert(pr.first);
                    break;
                }
        }
        
        return {ans.begin(), ans.end()};
    }
};