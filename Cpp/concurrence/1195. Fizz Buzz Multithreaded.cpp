class FizzBuzz {
private:
    int n;
    int i = 1;
    pthread_mutex_t m0 = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t m3 = PTHREAD_MUTEX_INITIALIZER;

    
public:
    FizzBuzz(int n) {
        this->n = n;
        pthread_mutex_lock(&m1);
        pthread_mutex_lock(&m2);
        pthread_mutex_lock(&m3);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (1) {
            pthread_mutex_lock(&m1);
            if (i++ > n) return;
            printFizz();
            pthread_mutex_unlock(&m0);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (1) {
            pthread_mutex_lock(&m2);
            if (i++ > n) return;
            printBuzz();
            pthread_mutex_unlock(&m0);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (1) {
            pthread_mutex_lock(&m3);
            if (i++ > n) return;
            printFizzBuzz();
            pthread_mutex_unlock(&m0);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (1) {
            pthread_mutex_lock(&m0);
            if (i > n) {
                pthread_mutex_unlock(&m1);
                pthread_mutex_unlock(&m2);
                pthread_mutex_unlock(&m3);
                return;
            }
            else if (i %15 == 0) pthread_mutex_unlock(&m3);
            else if (i % 3 == 0) pthread_mutex_unlock(&m1);
            else if (i % 5 == 0) pthread_mutex_unlock(&m2);
            else {
                printNumber(i++);
                pthread_mutex_unlock(&m0);
            }
        }
    }
};















class FizzBuzz {
private:
    int n;
    int i = 1;
    pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

    
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (1) {
            pthread_mutex_lock(&m);
            while (i % 3 != 0 || i % 15 == 0) {
                pthread_cond_wait(&cv, &m);
                if (i > n) {
                    pthread_mutex_unlock(&m);
                    pthread_cond_broadcast(&cv);
                    return;
                }
            }
            ++i;
            printFizz();
            pthread_mutex_unlock(&m);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (1) {
            pthread_mutex_lock(&m);
            while (i % 5 != 0 || i % 15 == 0) {
                pthread_cond_wait(&cv, &m);
                if (i > n) {
                    pthread_mutex_unlock(&m);
                    pthread_cond_broadcast(&cv);
                    return;
                }
            }
            ++i;
            printBuzz();
            pthread_mutex_unlock(&m);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (1) {
            pthread_mutex_lock(&m);
            while (i % 15 != 0) {
                pthread_cond_wait(&cv, &m);
                if (i > n) {
                    pthread_mutex_unlock(&m);
                    pthread_cond_broadcast(&cv);
                    return;
                }
            }
            ++i;
            printFizzBuzz();
            pthread_mutex_unlock(&m);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (i <= n) {
            pthread_mutex_lock(&m);
            if (i % 3 == 0 || i % 5 == 0) {
                pthread_mutex_unlock(&m);
                pthread_cond_broadcast(&cv);
            }
            else {
                printNumber(i++);
                pthread_mutex_unlock(&m);
            }
        }
        pthread_cond_broadcast(&cv);
    }
};