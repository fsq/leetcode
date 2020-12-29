class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> s(2);
        for (auto x : students) ++s[x];
        for (auto x : sandwiches) 
            if (s[x] == 0)
                return s[0] + s[1];
            else
                --s[x];
        return 0;
    }
};