class Solution {
public:
    
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        auto F = [](const string& s) {
            return count(s.begin(), s.end(), *min_element(s.begin(), s.end()));
        };
        vector<int> fw;
        for (auto& s : w) 
            fw.push_back(F(s));
        sort(fw.begin(), fw.end());
        vector<int> ans;
        for (auto& s : q) 
            ans.push_back(fw.size() - (upper_bound(fw.begin(), fw.end(), F(s)) - fw.begin()));
        
        return ans;
    }
};