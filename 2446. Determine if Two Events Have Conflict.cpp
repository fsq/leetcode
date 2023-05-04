class Solution {
public:
    bool haveConflict(vector<string>& a, vector<string>& b) {
        int x1 = stoi(a[0].substr(0, 2))*60 + stoi(a[0].substr(3, 2));
        int y1 = stoi(a[1].substr(0, 2))*60 + stoi(a[1].substr(3, 2));
        int x2 = stoi(b[0].substr(0, 2))*60 + stoi(b[0].substr(3, 2));
        int y2 = stoi(b[1].substr(0, 2))*60 + stoi(b[1].substr(3, 2));

        return max(x1, x2) <= min(y1, y2);
    }
};