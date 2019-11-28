class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 1;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> s(wordList.begin(), wordList.end());
        while (!q.empty()) {
            res++;
            int sz = q.size();
            while (sz--) {
                string t = q.front();            
                q.pop();            
                for (auto it = s.begin(); it != s.end();) {                
                    if (judge(t, *it)) {                    
                        if (*it == endWord) return res;                    
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        dict = unordered_set<string>(wordList.begin(), wordList.end());
        words1.insert(beginWord);
		words2.insert(endWord);
        if (!dict.count(endWord)) return 0;
		if (beginWord == endWord) return 1;
        return ladderLengthHelper(words1, words2, 1);
    }
private:
    unordered_set<string> dict, words1, words2;

    int ladderLengthHelper(unordered_set<string> &words1, unordered_set<string> &words2, int level) {
		if (words1.empty()) return 0;
		if (words1.size() > words2.size())
			return ladderLengthHelper(words2, words1, level);
		for (auto it : words1) dict.erase(it);
		for (auto it : words2) dict.erase(it);
        unordered_set<string> words3;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
			string word = *it;
			for (auto ch = word.begin(); ch != word.end(); ++ch) {
				char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch)) {
					if (*ch != tmp)
						if (words2.find(word) != words2.end())
                            return level + 1;
						else if (dict.find(word) != dict.end()) {
                            words3.insert(word);
                        }
                }
				*ch = tmp;
            }
        }
        return ladderLengthHelper(words2, words3, level+1);
    }
}