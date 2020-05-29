class Solution {
public:
    int ladderLength(string a, string b, vector<string>& v) {
        unordered_set<string> s(v.begin(), v.end());
        if (!s.count(b)) return 0;
        s.erase(a);
        s.erase(b);
        unordered_set<string> nextWords{a}, prevWords{b};
        int cnt = 2, n = a.length();
        while (!nextWords.empty() && !prevWords.empty()) {
            if (nextWords.size() > prevWords.size())
                swap(nextWords, prevWords);
            unordered_set<string> temp;
            for (auto t : nextWords) {
                string word = t;
                for (int p = 0; p < n; p++) {
                    char letter = word[p];
                    for (int j = 0; j < 26; j++) {
                        word[p] = 'a' + j; 
                        if (prevWords.count(word))
                            return cnt;
                        if (s.count(word)) {
                            temp.insert(word);
                            s.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            swap(nextWords, temp);
            cnt++; 
        }
        return 0;
    }
};
