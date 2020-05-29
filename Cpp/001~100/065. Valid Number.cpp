class Solution {
public:
    bool isNumber(string str) {
        int state = 0, flag = 0; 
        while (str[0]==' ')  str.erase(0,1); 
        while (str.back() == ' ') str.erase(str.length()-1);
        for (auto &c : str){
            if (isdigit(c)) {
                flag = 1;
                if (state <= 2) state = 2;
                else state = (state <= 5) ? 5 : 7;
            }
            else if('+' == c || '-' == c){
                if (state == 0 || state == 3) state++;
                else return false;
            }
            else if('.' == c){
                if (state <= 2) state = 6;
                else return false;
            }
            else if('e' == c){
                if(flag && (state == 2 || state == 6 || state == 7)) state = 3;
                else return false;
            }
            else return false;
        }
        return state == 2 || state == 5 || (flag && state == 6) || state == 7;
    }
};
