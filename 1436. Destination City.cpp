class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> to, from;
        for (auto& p : paths) {
            to.insert(p[1]);
            from.insert(p[0]);
        }
        for (auto& f : to)
            if (!from.count(f))
                return f;
        return "";
    }
};