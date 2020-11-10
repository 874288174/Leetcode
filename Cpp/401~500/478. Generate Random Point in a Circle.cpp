/*
class Solution {
public:
    Solution(double r, double x, double y) :r(r), x(x), y(y) {}
    
    vector<double> randPoint() {
        double xx, yy;
        do {
            xx = uni(rng);
            yy = uni(rng);
        } while (xx*xx + yy*yy > 1);
        return vector<double> {r*xx + x, r*yy + y};
    }
    
private:
    double r, x, y;
    //c++11 random floating point number generation
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{-1, 1};
};
*/

class Solution {
public:
    Solution(double r, double x, double y) :r(r), x(x), y(y) {}

    vector<double> randPoint() {
        double d = r * sqrt(uni(rng));
        double theta = uni(rng) * (2 * M_PI);
        return {d * cos(theta) + x, d * sin(theta) + y};
    }

private:
    double r, x, y;
    //c++11 random floating point number generation
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};
};


/*
在半径r、R上的点应该满足f(r)/r = f(R)/R = C
由归一性得f(x) = 2x
现在问题是已经有U (0,1均匀分布，f(x)=1)该如何得到V (f(x)为2x)
Fu(x) = P(U < x) = x = Fv(Fv^-1(x)) = P(V < Fv^-1(x)) = P(Fv(V) < x)
所以U = Fv(V)=V^2， 即V=sqrt(U)
*/