class Solution {
public:
    int ladderLength(string a, string b, vector<string>& v) {
        int res = 1;
        queue<string> q;
        q.push(a);
        unordered_set<string> s(v.begin(), v.end());
        while (!q.empty()) {
            res++;
            int sz = q.size();
            while (sz--) {
                string t = q.front();            
                q.pop();            
                for (auto it = s.begin(); it != s.end();) {                
                    if (judge(t, *it)) {                    
                        if (*it == b) return res;                    
                        q.push(*it);                    
                        it = s.erase(it);                
                    }               
                    else it++;            
                }
            }
        }
        return 0;
    }

private:
    bool judge(const string &a, const string &b) {
        if (a.length() != b.length()) return false;
        int cnt = 0, len = a.length();
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i] && ++cnt > 1) {
                return false;
            }
        }
        return cnt == 1;
    }    
};



/////////////////////////////////////////////////////////
class Solution {
public:
    int ladderLength(string a, string b, vector<string>& v) {
        unordered_set<string> s(v.begin(), v.end());
        if (!s.count(b)) return 0;
        s.erase(a);
        s.erase(b);
        unordered_set<string> nextWords{a}, prevWords{b};
        int ladder = 2, len = a.length();
        while (!nextWords.empty() && !prevWords.empty()) {
            if (nextWords.size() > prevWords.size())
                swap(nextWords, prevWords);
            unordered_set<string> temp;
            for (auto s : nextWords) {
                string word = s;
                for (int p = 0; p < len; p++) {
                    char letter = word[p];
                    for (int j = 0; j < 26; j++) {
                        word[p] = 'a' + j; 
                        if (prevWords.count(word))
                            return ladder;
                        if (s.count(word)) {
                            temp.insert(word);
                            s.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            swap(nextWords, temp);
            ladder++; 
        }
        return 0;
    }
};
