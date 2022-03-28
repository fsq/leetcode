class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream sin(s);
        int prev = INT_MIN;
        string w;
        while (sin >> w) {
            if (isdigit(w[0])) {
                int x = stoi(w);
                if (x <= prev) return false;
                prev = x;
            }
        }
        return true;
    }
};