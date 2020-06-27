class Solution {
public:
    // three
    // nine
    string originalDigits(string st) {
        vector<int> cnt(127);
        for (auto x : st) ++cnt[x];
        vector<int> a(10);
        vector<string> s = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        a[0] = cnt['z'];
        a[2] = cnt['w'];
        a[4] = cnt['u'];
        a[6] = cnt['x'];
        a[8] = cnt['g'];
        for (int i=0; i<10; i+=2)
            for (auto x : s[i])
                cnt[x] -= a[i];
        a[5] = cnt['f'];
        for (auto x : s[5]) cnt[x] -= a[5];
        a[7] = cnt['v'];
        for (auto x : s[7]) cnt[x] -= a[5];
        a[1] = cnt['o'];
        for (auto x : s[1]) cnt[x] -= a[1];
        a[9] = cnt['i'];
        a[3] = cnt['h'];
        string ans;
        for (int i=0; i<10; ++i) ans += string(a[i], i+'0');
        return ans;
    }
};