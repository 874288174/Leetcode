class Solution {
public:
    using ull = unsigned long long;
    const ull base = 37;
    const string code = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const ull len = code.size();
    unordered_map<string, string> m;
    
    ull hashcode(const string& s) {
        //return hash<string>() (s);
        ull hash = 0;
        for (auto c : s) {
            hash *= base;
            hash += c;
        }
        return hash;
    }
    
    string ULLToString(ull n) {
        string s;
        while (n != 0) {
            s += code[n % len];
            n /= len;
        }
        return s;
    }
    
    string encode(string longUrl) {
        string shortUrl = ULLToString(hashcode(longUrl));
        m[shortUrl] = longUrl;
        return shortUrl;
    }

    string decode(string shortUrl) {
        return m[shortUrl];
    }
};