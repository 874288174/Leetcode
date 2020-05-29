class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        dict = unordered_set<string>(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
		if (beginWord == endWord) return {path};
        words1.insert(beginWord);
		words2.insert(endWord);
        path.push_back(beginWord);
        
        if (findLaddersHelper(words1, words2))
			getPath(beginWord, endWord);
		return res;
    }
private:
    unordered_set<string> dict, words1, words2;
    unordered_map<string, vector<string> > nexts;
    vector<string> path;
    vector<vector<string>> res;
    bool words1IsBegin = false;
    
    bool findLaddersHelper(unordered_set<string> &words1, unordered_set<string> &words2) {
		words1IsBegin = !words1IsBegin;
		if (words1.empty()) return false;
		if (words1.size() > words2.size())
			return findLaddersHelper(words2, words1);
		for (auto it : words1) dict.erase(it);
		for (auto it : words2) dict.erase(it);
        unordered_set<string> words3;
		bool reach = false;
        for (const auto &it : words1) {
			string word = it;
			for (auto &ch : word) {
				char tmp = ch;
                for (ch = 'a'; ch <= 'z'; ++(ch)) if (ch != tmp) {
                    if (words2.count(word)) {
                        reach = true;
                        words1IsBegin ? nexts[it].push_back(word) : nexts[word].push_back(it);
                    } else if (!reach && dict.count(word)) {
                        words3.insert(word);
                        words1IsBegin ? nexts[it].push_back(word) : nexts[word].push_back(it);    
                    }
                }
				ch = tmp;
            }
        }
        return reach || findLaddersHelper(words2, words3);
    }
    
	void getPath(const string &beginWord, const string &endWord) {
		if (beginWord == endWord)
			res.push_back(path);
		else for (auto it : nexts[beginWord]) {
			path.push_back(it);
			getPath(it, endWord);
			path.pop_back();
		}
	}
};