class Solution {
public:
    int time(string& a) {
        return stoi(a.substr(0, 2)) * 60 + stoi(a.substr(2));
    }
    int df(string& a, string& b) {
        return time(b) - time(a);
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<string>> m;
        for (auto& pr : access_times) {
            m[pr[0]].push_back(pr[1]);
        }
        vector<string> ans;
        for (auto& pr : m) {
            auto& a = pr.second;
            if (a.size() < 3) continue;
            sort(a.begin(), a.end());
            bool ok = false;
            for (int i=0; i+2<a.size(); ++i) {
                if (df(a[i], a[i+1])<60 && df(a[i], a[i+2])<60) {
                    ok = true;
                    break;
                }
            }
            if (ok) ans.push_back(pr.first);
        }
        return ans;
    }
};