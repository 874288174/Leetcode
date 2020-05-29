class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size(), i = 0;
        while (i < n) {
            int width = 0;
            vector<string> t;
            while (i < n && width + words[i].length() <= maxWidth-t.size()) {
                width += words[i].length();
                t.push_back(words[i++]);
            }   
            string s = t[0]; 
            int space_num = maxWidth-width;
            if (t.size() == 1)   s += string(space_num, ' ');
            else if (i == n) {
                for (int j = 1; j < t.size(); ++j) {
                    s += " " + t[j];
                }
                s += string(maxWidth - s.length(), ' ');
            }
            else {
                int aver = space_num / (t.size()-1);
                int k = space_num - (t.size()-1)*aver;
                for (int j = 1; j < t.size(); ++j) {
                    s += string((j <= k ? aver+1: aver), ' ') + t[j];
                }
            }
            res.push_back(s);
        }
        return res;
    }
};
