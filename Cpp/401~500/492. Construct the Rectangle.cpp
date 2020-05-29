class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = sqrt(area);
        while (1) {
            if (area % W == 0) return {area/W, W};
            else W--;
        }
        return {area, 1};
    }
};