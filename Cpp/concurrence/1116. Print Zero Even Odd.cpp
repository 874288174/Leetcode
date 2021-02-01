class ZeroEvenOdd {
private:
    int n;
    int i = 1;
    pthread_mutex_t m0 = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        pthread_mutex_lock(&m1);
        pthread_mutex_lock(&m2);
    }

    void unlockAll() {
        pthread_mutex_unlock(&m1);
        pthread_mutex_unlock(&m2);
    }
    
    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (1) {
            pthread_mutex_lock(&m0);
            if (i > n) {unlockAll(); return;}
            printNumber(0);
            if (i&1) pthread_mutex_unlock(&m1);
            else pthread_mutex_unlock(&m2);
        }
    }

    void even(function<void(int)> printNumber) {
        while (1) {
            pthread_mutex_lock(&m2);
            if (i > n) return;
            printNumber(i++);
            pthread_mutex_unlock(&m0);
        }
    }

    void odd(function<void(int)> printNumber) {
        while (1) {
            pthread_mutex_lock(&m1);
            if (i > n) return;
            printNumber(i++);
            pthread_mutex_unlock(&m0);
        }
    }
};











class ZeroEvenOdd {
private:
    int n;
    pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

    bool stop = false;
    int flag = 0;
    
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            pthread_mutex_lock(&m);
            while (flag != 0) {
                pthread_cond_wait(&cv, &m);
            }
            printNumber(0);
            flag = i % 2 ? 2 : 1;
            pthread_mutex_unlock(&m);
            pthread_cond_broadcast(&cv);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            pthread_mutex_lock(&m);
            while (flag != 1) {
                pthread_cond_wait(&cv, &m);
            }
            printNumber(i);
            flag = 0;
            pthread_mutex_unlock(&m);
            pthread_cond_broadcast(&cv);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            pthread_mutex_lock(&m);
            while (flag != 2) {
                pthread_cond_wait(&cv, &m);
            }
            
            printNumber(i);
            flag = 0;
            pthread_mutex_unlock(&m);
            pthread_cond_broadcast(&cv);
        }
    }
};