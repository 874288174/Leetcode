/*
class Solution {
public:
    Solution(double r, double x, double y) :r(r), x(x), y(y) {}
    
    vector<double> randPoint() {
        double xx, yy;
        do {
            xx = 2*rand1() - 1;
            yy = 2*rand1() - 1;
        } while (xx*xx + yy*yy > 1);
        return vector<double> {r*xx + x, r*yy + y};
    }
    
private:
    double r, x, y;
    double rand1() {return (double)rand() / RAND_MAX;}
};
*/

class Solution {
public:	
    Solution(double r, double x, double y) :r(r), x(x), y(y) {}
    
    vector<double> randPoint() {
        double theta = 2 * PI * rand1();
        double rr = sqrt(rand1());
        return vector<double> {x + rr*r*cos(theta),y + rr*r*sin(theta)};
    }
    
private:
    const double PI = 3.14159265358979732384626433832795;	
    double r, x, y;
    
    double rand1() {return (double)rand() / RAND_MAX;}
};