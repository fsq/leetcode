class Solution {
public:
    set<pair<long long,int>> use;
    set<int> free;

    int mostBooked(int n, vector<vector<int>>& mtg) {
        for (int i=0; i<n; ++i) free.insert(i);
        vector<int> score(n);
        long long t = 0;

        sort(mtg.begin(), mtg.end());
        for (auto& mt : mtg) {
            if (use.size()==n) {
                t = max<long long>(t, use.begin()->first);
            }
            t = max<long long>(t, mt[0]);
            while (use.size() && use.begin()->first<=t) {
                int x = use.begin()->second;
                use.erase(use.begin());
                free.insert(x);
            }
            int x = *free.begin();
            free.erase(free.begin());
            use.insert({t+mt[1]-mt[0], x});
            ++score[x];
        }
        return max_element(score.begin(), score.end()) - score.begin();
    }
};