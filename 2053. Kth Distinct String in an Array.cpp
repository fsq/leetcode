class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> cnt;
        for (auto& s : arr) ++cnt[s];
        int ind = 0;
        for (auto& s : arr)
            if (cnt[s] == 1 && ++ind==k)
                return s;
        return "";
    }
};