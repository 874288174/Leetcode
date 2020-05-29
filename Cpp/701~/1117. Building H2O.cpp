class H2O {
    int h = 0;
    mutex m;
    condition_variable cv;
public:
    
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> l(m);
        cv.wait(l, [=]{return h != 2;});
        releaseHydrogen();
        h++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> l(m);
        cv.wait(l, [=]{return h == 2;});
        releaseOxygen();
        h = 0;
        cv.notify_all();
    }
};