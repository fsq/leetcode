class TopVotedCandidate {
public:
    
    vector<int> time;
    vector<int> id;
    
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        vector<int> cnt(persons.size()+1);
        int maxCnt = 0;
        for (int i=0; i<times.size(); ++i) {
            ++cnt[persons[i]];
            if (cnt[persons[i]]>=maxCnt) {
                time.push_back(times[i]);
                id.push_back(persons[i]);
                maxCnt = max(maxCnt, cnt[persons[i]]);
            }
        }
    }
    
    int q(int t) {
        int i = upper_bound(time.begin(), time.end(), t) - time.begin() - 1;
        return id[i];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */