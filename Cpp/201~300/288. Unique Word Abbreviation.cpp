
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(auto &s : dictionary) {
            string a = s[0] + to_string(s.length()-2) + s.back();
            if (m.count(a) && m[a] != s) m[a] = "";
            else m[a] = s;
        }
    }
    
    bool isUnique(string word) {
        string s = word[0] + to_string(word.length()-2) + word.back();
        return !m.count(s) || m[s] == word;
    }
private:
    unordered_map<string, string> m;
};
