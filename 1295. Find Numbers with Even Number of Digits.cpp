class Solution {
public:
    int findNumbers(vector<int>& a) {
        return count_if(a.begin(), a.end(), [](int x) {
            return (to_string(x).size() & 1) == 0;
        });
    }
};