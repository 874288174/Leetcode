class Solution {
public:
    string validIPAddress(string IP) {
        string s;
        int cnt = 0;
        if (IP.find('.') != string::npos) {    
            for (auto &c : IP) {
                if (c == '.' && ++cnt) c = ' ';    
                else if (!isdigit(c)) return "Neither";
            }   
            if (cnt != 3) return "Neither";         
            stringstream ss(IP);     
            while(ss >> s) {   
                --cnt;  
                if (s.empty() || s.length() > 3 || stoi(s) > 255) {  
                    return "Neither"; 
                } else if (s[0] == '0' && s != "0") {       
                    return "Neither";          
                }     
            }     
            return cnt == -1 ? "IPv4" : "Neither";
        } else {
            for (auto &c : IP) { 
                if (c == ':' && ++cnt)  c = ' ';
                else if (!isalnum(c)) return "Neither";
                else if (isalpha(c) && (isupper(c) ? c > 'F': c > 'f' )) return "Neither";
            }
            if (cnt != 7) return "Neither";
            stringstream ss(IP);
            while(ss >> s) {
                --cnt;
               if (s.empty() || s.length() > 4) {
                   return "Neither";
               }
            }
            return cnt == -1 ? "IPv6" : "Neither";
        }
        return "Neither";
    }
};