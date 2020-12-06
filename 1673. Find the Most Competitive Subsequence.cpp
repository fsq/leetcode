class Solution {
public:
    vector<int> mostCompetitive(vector<int>& a, int k) {
        vector<int> ans;
        for (int i=0; i<a.size(); ++i) {
            while (ans.size() && a[i]<ans.back() && a.size()-i+ans.size()-1>=k) 
                ans.pop_back();
            if (ans.size()<k) ans.push_back(a[i]);
        }
        return ans;
    }
};