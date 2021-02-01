class Foo {
public:
    pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

    
    Foo() {
        pthread_mutex_lock(&m1);
        pthread_mutex_lock(&m2);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        pthread_mutex_unlock(&m1);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&m1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        pthread_mutex_unlock(&m2);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&m2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};









class Foo {
public:
    int cnt = 1;
    pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
	
    Foo() {}

    void first(function<void()> printFirst) {
        pthread_mutex_lock(&m);
        while (cnt != 1) { 
            pthread_cond_wait(&cv, &m);
        }
        
        printFirst();
        cnt = 2;
        pthread_mutex_unlock(&m);
        pthread_cond_broadcast(&cv);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&m);
        while (cnt != 2) { 
            pthread_cond_wait(&cv, &m);
        }
        
        printSecond();
        cnt = 3;
        pthread_mutex_unlock(&m);
        pthread_cond_broadcast(&cv);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&m);
        while (cnt != 3) {
             pthread_cond_wait(&cv, &m);
        }
        
        printThird();
        pthread_mutex_unlock(&m);
    }
};