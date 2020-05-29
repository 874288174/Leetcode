class Solution {
public:
    int compareVersion(string version1, string version2) {
        for(auto &c : version1) if(c == '.') c = ' ';
        for(auto &c : version2) if(c == '.') c = ' ';
        istringstream s1(version1), s2(version2);
        while (s1 || s2) {
            int a = 0, b = 0;
            s1 >> a;  
            s2 >> b; 
            if (a < b) return -1;
            else if (a > b) return 1;
        }
        return 0;
    }
};