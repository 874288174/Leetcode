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