class Solution {
public:
    int convertTime(string current, string correct) {
        int cur = stoi(current.substr(0, 2))*60 + stoi(current.substr(3, 2));
        int tar = stoi(correct.substr(0, 2))*60 + stoi(correct.substr(3, 2));
        cur = tar - cur;
        int ans = cur / 60; cur %= 60;
        ans += cur/15; cur %= 15;
        ans += cur/5; cur %= 5;
        ans += cur;
        return ans;
    }
};