class DataStream {
public:
    int v, k, pre;

    DataStream(int _value, int _k) {
        v = _value;
        k = _k;
        pre = 0;
    }
    
    bool consec(int num) {
        pre = num==v ? pre+1 : 0;
        return pre>=k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */