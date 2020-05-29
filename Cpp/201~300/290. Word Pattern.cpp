class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str), sss(pattern); 
        int cnt = 0;
        char c; 
        unordered_map<char, int>a;
        unordered_map<string,int>b;
        while (ss >> str) {
            if(!(sss >> c)) return false;
            if(b[str] != a[c]) return false;
            if(!a[c]) a[c] = b[str] = ++cnt;
        }
        return sss>>c ? false : true;
    }
};