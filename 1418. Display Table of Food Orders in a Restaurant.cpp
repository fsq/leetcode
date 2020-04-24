class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<unordered_map<string, int>> m(501);
        set<string> ds;
        for (auto& order : orders) {
            int id = stoi(order[1]);
            string& d = order[2];
            ds.insert(d);
            ++m[id][d];
        }
        vector<vector<string>> ans;
        vector<string> header = {"Table"};
        header.insert(header.end(), ds.begin(), ds.end());
        ans.push_back(std::move(header));
        for (int i=1; i<=500; ++i)
            if (!m[i].empty()) {
                vector<string> row;
                row.push_back(to_string(i));
                for (auto& d : ds)
                    if (m[i].count(d))
                        row.push_back(to_string(m[i][d]));
                    else
                        row.push_back("0");
                ans.push_back(std::move(row));
            }
        return ans;
    }
};