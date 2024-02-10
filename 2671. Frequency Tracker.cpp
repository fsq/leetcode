class FrequencyTracker {
public:
    unordered_multiset<int> s;
    unordered_map<int, int> f;

    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if (f[number] > 0) {
            s.erase(s.find(f[number]));
        }
        s.insert(++f[number]);
    }
    
    void deleteOne(int number) {
        if (f[number] > 0) {
            s.erase(s.find(f[number]));
            s.insert(--f[number]);
        }
    }
    
    bool hasFrequency(int frequency) {
        return s.find(frequency) != s.end();
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */