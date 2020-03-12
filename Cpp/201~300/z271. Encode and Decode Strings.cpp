class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto s : strs) {
           string t(to_string(s.length()));
           res += string(3 - t.length(), '0') + t + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, n = s.length();
        while (i < n) {
            int k = stoi(s.substr(i, 3));
            res.push_back(s.substr(i+3, k));
            i += 3 + k;
        }
        return res;
    }
};