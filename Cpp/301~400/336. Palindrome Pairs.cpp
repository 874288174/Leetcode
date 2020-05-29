class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> dict;
        int i, j, n = words.size();
        for(i = 0; i < n; i++) {
            string t = words[i];
            reverse(t.begin(), t.end());
            dict[t] = i;
        }
        
        for(i = 0; i < n; i++) {
            for(j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (dict.count(left) && dict[left] != i && isPalindrome(right)) {
                    res.push_back({i, dict[left]});
                    if (left.empty()) res.push_back({dict[left], i});
                }
                if (dict.count(right) && dict[right] != i && isPalindrome(left)) {
                    res.push_back({dict[right], i});
                }
            }
        }
        return res;
    }
    
private:
    bool isPalindrome(string s) {
        int start, end, n = s.size();
        for(start = 0, end = n - 1; start < end; start++, end--) {
            if(s[start] != s[end])
                return false;
        }
        return true;
    }
};