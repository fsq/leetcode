
class Solution {
public:
    string minCostGoodCaption(string caption) {
        int n = caption.length();
        if (n < 3) return "";

        const int INF = 1e9;
        // f[i][length_of_group][char_index]
        // length_of_group: 1, 2, or 3 (where 3 means 3 or more)
        struct State {
            int cost;
            int next_char;
        };

        vector<vector<vector<State>>> f(n + 1, vector<vector<State>>(4, vector<State>(26, {INF, 0})));

        for (int pre = 0; pre < 26; ++pre) {
            f[n][3][pre] = {0, 0};
        }

        for (int i = n - 1; i >= 0; --i) {
            int cc = caption[i] - 'a';
            for (int pre = 0; pre < 26; ++pre) {
                f[i][1][pre] = {f[i + 1][2][pre].cost + abs(cc - pre), pre};
                f[i][2][pre] = {f[i + 1][3][pre].cost + abs(cc - pre), pre};
                State best = {INF, 0};
                for (int nxt = 0; nxt < 26; ++nxt) {
                    int current_cost = f[i + 1][(nxt == pre ? 3 : 1)][nxt].cost + abs(cc - nxt);
                    if (current_cost < best.cost) {
                        best = {current_cost, nxt};
                    }
                }
                f[i][3][pre] = best;
            }
        }

        int min_total_cost = INF;
        int start_char = 0;
        for (int fst = 0; fst < 26; ++fst) {
            int cost = f[1][1][fst].cost + abs((caption[0] - 'a') - fst);
            if (cost < min_total_cost) {
                min_total_cost = cost;
                start_char = fst;
            }
        }


        string result = "";
        int curr_l = 1;
        int curr_pre = start_char;
        result += (char)('a' + start_char);

        for (int i = 1; i < n; ++i) {
            int next_c = f[i][curr_l][curr_pre].next_char;
            result += (char)('a' + next_c);
            if (next_c == curr_pre) {
                curr_l = min(3, curr_l + 1);
            } else {
                curr_l = 1;
            }
            curr_pre = next_c;
        }

        return result;
    }
};
