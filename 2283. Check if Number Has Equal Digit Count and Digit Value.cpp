class Solution {
public:
    bool digitCount(string num) {
        vector<int> c(10);
        for (auto x : num) ++c[x-'0'];
        for (int i=0; i<num.size(); ++i)
            if (c[i] != num[i]-'0')
                return false;
        return true;
    }
};