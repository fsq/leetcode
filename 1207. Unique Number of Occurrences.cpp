class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> c;
        for (auto x : arr) ++c[x];
        unordered_set<int> st;
        for (auto& pr : c)
            if (st.count(pr.second))
                return false;
            else
                st.insert(pr.second);
        return true;
    }
};