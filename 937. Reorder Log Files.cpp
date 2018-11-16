class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& a, const string& b)->bool {
            int i = a.find(' '), j = b.find(' ');
            string x = a.substr(i+1), y = b.substr(j+1);
            if (isalpha(x[0]) && isalpha(y[0]))
                return x < y;
            else if (isdigit(x[0]) && isdigit(y[0]))
                return false;
            else
                return isdigit(y[0]);
        });
        return logs;
    }
};