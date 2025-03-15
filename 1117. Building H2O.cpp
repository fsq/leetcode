class H2O {
public:
    mutex m;
    // guarantee "HHO" by thread arrival order, not required to pass the oj
    queue<pair<condition_variable*, function<void()>>> hq, oq;

    H2O() {
        
    }

    void Pass(unique_lock<mutex>* lk) {
        auto [cvh1, f1] = hq.front(); hq.pop();
        invoke(f1); 
        auto [cvh2, f2] = hq.front(); hq.pop();
        invoke(f2); 
        auto [cvo, f3] = oq.front(); oq.pop();
        invoke(f3); 
        lk->unlock();
        cvh1->notify_one();
        cvh2->notify_one();
        cvo->notify_one();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock lk(m);
        condition_variable cv;
        hq.push({&cv, releaseHydrogen});
        if (hq.size()>=2 && oq.size()>=1) {
            Pass(&lk);
            return;
        }
        cv.wait(lk);
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock lk(m);
        condition_variable cv;
        oq.push({&cv, releaseOxygen});
        if (hq.size()>=2 && oq.size()>=1) {
            Pass(&lk);
            return;
        }
        cv.wait(lk);
    }
};