class Solution {
public:
    int ans = 0;

    void dfs(string& time, int i) {
        if (i==time.size()) {
            int h = stoi(time.substr(0, 2)), m = stoi(time.substr(3, 2));
            if (h<=23 && m<=59) ++ans;
        } else {
            if (time[i]!='?')
                dfs(time, i+1);
            else {
                for (time[i]='0'; time[i]<='9'; ++time[i]) {
                    dfs(time, i+1);
                }
                time[i] = '?';
            }
        }
    }

    int countTime(string time) {
        dfs(time, 0);
        return ans;
    }
};