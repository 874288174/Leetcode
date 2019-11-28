class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res, t;
        size_t n = words.size(), i = 0;
        int width = 0;
        while (i < n) {
            if (width + words[i].length() <= maxWidth-t.size()) {
                width += words[i].length();
                t.push_back(words[i++]);
            }
            else {
                string s = t[0]; 
                int space_num = maxWidth-width;
                if (t.size() == 1)   s += string(space_num, ' ');
                else {
                    int aver = space_num / (t.size()-1);
                    int k = space_num - (t.size()-1)*aver;
                    for (int j = 1; j < t.size(); ++j) {
                        s += string((j <= k ? aver+1: aver), ' ') + t[j];
                    }
                }
                res.push_back(s);
                t.clear();
                width = 0;
            }
        }
        string s = t[0];
        for (int j = 1; j < t.size(); j++) s += ' ' + t[j];
        s += string(maxWidth-s.length(), ' ');
        res.push_back(s);
        return res;
    }
}