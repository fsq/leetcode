class Solution {
public:
    
    string findSmallestRegion(vector<vector<string>>& regions, string s, string t) {
        unordered_map<string, string> fa;
        for (auto& r : regions)
            for (int i=1; i<r.size(); ++i)
                fa[r[i]] = r[0];
        unordered_set<string> fs;
        for (string x=s; !x.empty(); x=fa[x]) fs.insert(x);
        for (string x=t; !x.empty(); x=fa[x]) 
            if (fs.count(x)) return x;
        return "";
    }
};