class H2O {
public:
    pthread_mutex_t m0 = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
    int h = 0;
    
    H2O() {
        pthread_mutex_lock(&m1);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        pthread_mutex_lock(&m0);
        releaseHydrogen();
        if (++h % 2 == 0) pthread_mutex_unlock(&m1);
        else pthread_mutex_unlock(&m0);
    }

    void oxygen(function<void()> releaseOxygen) {
        // releaseOxygen() outputs "O". Do not change or remove this line.
        pthread_mutex_lock(&m1);
        releaseOxygen();
        pthread_mutex_unlock(&m0);
    }
};