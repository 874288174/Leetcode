class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty()) return 0;
        
        int n = image.size(), m = image[0].size();
        int left  = horizontalSearch(0, y, 0, n, image, '1');
        int right = horizontalSearch(y + 1, m, 0, n, image, '0');
        int up    = verticalSearch(0, x, left, right, image, '1');  
        int down  = verticalSearch(x + 1, n, left, right, image, '0');   
        return (right - left) * (down - up);
    }
private:
    int horizontalSearch(int start, int end, int top, int bottom, vector<vector<char>>& image, char target) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            int temp_top = top;
            char found = '0';
            while (temp_top < bottom) {
                if (image[temp_top++][mid] == '1') {
                    found = '1'; 
                    break;
                }
            }
            if (target == found) end = mid;
            else start = mid + 1;
        }
        return start;
    }
    
    int verticalSearch(int start, int end, int left, int right, vector<vector<char>>& image, char target) { 
        while(start < end) {
            int mid = start + (end - start) / 2;
            int temp_left = left;
            char found = '0';
            while(temp_left < right) {
                if(image[mid][temp_left++] == '1') {
                    found = '1'; 
                    break;
                }
            }
            if (target == found) end = mid;
            else start = mid + 1;
        }
        return start;
    }
};