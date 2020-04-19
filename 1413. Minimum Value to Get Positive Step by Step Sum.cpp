class Solution {
public:
    int minStartValue(vector<int>& a) {
        for (int i=1; i<a.size(); ++i)
            a[i] += a[i-1];
        return max(1, -*min_element(a.begin(), a.end())+1);
    }
};