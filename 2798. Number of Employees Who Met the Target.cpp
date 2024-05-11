class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& a, int target) {
        return count_if(a.begin(), a.end(), [=](int x) -> bool {
            return x >= target;
        });
    }
};