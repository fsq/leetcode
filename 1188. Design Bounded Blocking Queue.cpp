class BoundedBlockingQueue {
public:
    shared_mutex m; // reader/writer lock for concurrent size() call
    queue<int> q;
    condition_variable_any en_cv, de_cv;
    int cap;

    BoundedBlockingQueue(int capacity):cap(capacity) {
    }
    
    void enqueue(int element) {
        unique_lock lk(m);
        en_cv.wait(lk, [this](){ return q.size()<cap; });
        q.push(element);
        lk.unlock();
        de_cv.notify_one();
    }
    
    int dequeue() {
        unique_lock lk(m);
        de_cv.wait(lk, [this](){ return !q.empty(); });
        auto ret = q.front();
        q.pop();
        lk.unlock();
        en_cv.notify_one();
        return ret;
    }
    
    int size() {
        shared_lock lk(m);
        return q.size();
    }
};