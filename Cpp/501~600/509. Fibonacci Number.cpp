class Solution {
public:
    struct Matrix{
        int a[2][2] = {0};
        void init(){
            for (int i = 0; i < 2; i++)
               a[i][i] = 1;
        }
    };
    
    Matrix MUL(Matrix A, Matrix B){
        Matrix C;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++){
                    C.a[i][j] += A.a[i][k] * B.a[k][j];
                }
            }
        }
        return C;
    }
    

    int fib(int n) {
        Matrix res, x;
        x.a[0][0] = x.a[0][1] = x.a[1][0] = 1;
        x.a[1][1] = 0;
        res.init();
        while (n) {
            if (n&1) res = MUL(res, x);
            x = MUL(x, x);
            n >>= 1;
        }
        return res.a[1][0];
    }
};