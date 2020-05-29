class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string res;
        while (ss >> res);
        return res.length();
    }
};




///////////////////////////////////////////////////////////////
class Solution {
public:
    int lengthOfLastWord(string s) {
        s += ' ';
        int len = 0, res = 0;
        for (auto &i : s) {
            if (i != ' ') len++;
            else if (len != 0){
                res = len;
                len = 0;
            }
        }
        return res;
    }
}