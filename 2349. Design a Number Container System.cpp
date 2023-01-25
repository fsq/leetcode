class NumberContainers {
public:
    unordered_map<int, int> m;
    unordered_map<int, set<int>> p;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int pre = m[index];
        if (pre != 0) {
            p[pre].erase(index);
            if (p[pre].empty()) p.erase(pre);
        }
        m[index] = number;
        p[number].insert(index);
    }
    
    int find(int number) {
        if (p.count(number)) {
            return *p[number].begin();
        } else {
            return -1;
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */