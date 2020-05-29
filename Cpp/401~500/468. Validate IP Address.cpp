class Solution {
public:
    string validIPAddress(string IP) {
        regex ipv4("^(?:(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]\\d|\\d)(\\.(?!$)|$)){4}$");   
        regex ipv6("^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$");
        if (regex_match(IP,ipv4)) return "IPv4";
        else if (regex_match(IP,ipv6)) return "IPv6";
        else return "Neither";
    }
};