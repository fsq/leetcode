class Solution {
public:
    vector<int> ds = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int f(const string& s) {
        int m = stoi(s.substr(0, 2)), d = stoi(s.substr(3, 2)), ans = 0;
        for (int i=1; i<m; ++i) ans += ds[i];
        ans += d;
        return ans;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string a = max(arriveAlice, arriveBob), b = min(leaveAlice, leaveBob);
        if (a > b) return 0;
        return f(b) - f(a) + 1;
    }
};