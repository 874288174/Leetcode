class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string sid = ToBase62(id++);
        urls[sid] = longUrl;
        return sid;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urls[shortUrl];
    }
private:
    const string base62c = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"s;
    int id = 0;
    unordered_map<string, string> urls;
    
    string ToBase62(int base10) {
        string base62;
        while (base10) {
            base62 += base62c[base10 % 62];
            base10 /= 62;
        }
        reverse(base62.begin(), base62.end());
        return base62;
    }
};




class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (url2code.count(longUrl)) return url2code[longUrl];
        
        string code;
        do {
            for (int i = 0; i < 6; ++i) code += base62c[rand() % 62];
        } while(code2url.count(code));
        
        code2url[code] = longUrl;  
        url2code[longUrl] = code;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return code2url[shortUrl];
    }
    
private:
    const string base62c = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"s;
    unordered_map<string, string> url2code, code2url;
};

