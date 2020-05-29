class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            string t;
            char c = s[0];
            int cnt = 1;
            for(int i = 1; i < s.length(); i++){
                if (s[i] == c) cnt++;
                else {
                    t += to_string(cnt)+c;
                    cnt = 1;
                    c = s[i]; 
                }
            }
            s = t + to_string(cnt)+c;
        }
        return s;
    }
};