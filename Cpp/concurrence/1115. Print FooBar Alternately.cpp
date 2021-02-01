class FooBar {
private:
    int n;
    pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
public:
    FooBar(int n) {
        this->n = n;
        pthread_mutex_lock(&m2);
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&m1);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            pthread_mutex_unlock(&m2);

        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&m2);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            pthread_mutex_unlock(&m1);
        }
    }
};







class FooBar {
private:
    int n;
    pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
    bool flag = false;
    
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&m);
            while (flag) {
                pthread_cond_wait(&cv, &m);
            }
            flag = !flag;

        	printFoo();
            pthread_mutex_unlock(&m);
            pthread_cond_broadcast(&cv);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&m);
            while (!flag) {
                pthread_cond_wait(&cv, &m);
            }
            flag = !flag;

        	printBar();
            pthread_mutex_unlock(&m);
            pthread_cond_broadcast(&cv);
        }
    }
};